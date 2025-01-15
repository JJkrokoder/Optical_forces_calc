/**
 * @file optical_forces_calc_DA.h
 * @brief Optical forces calculation using the dipolar approximation.
 * 
 * This file contains the implementation of the `calculateOpticalForces` function,
 * which computes the optical forces acting on particles using the dipolar approximation.
 * The function implements the formula:
 * 
 *      F_j = (ε_m / 2) Re{p · ∂_jE*}
 * 
 * where F_j is the force on a particle in the j-th spatial direction.
 *
 * @param dipole_moments Vector of complex dipole moments for N particles.
 *        Size: num_particles * dimensions.
 * @param field_gradients Vector of complex electric field gradients.
 *        Size: num_particles * dimensions * dimensions.
 * @param epsilon_m Medium permittivity (scalar value).
 * @param num_particles Number of particles in the system.
 * @param dimensions Number of spatial dimensions (typically 3).
 * @param forces_array Vector where the calculated forces will be stored.
 *        Must be pre-allocated with size num_particles * dimensions.
 *
 * @throws std::invalid_argument If the dimensions of any input vector do not match the expected sizes.
 *
 * @note Input vector dimensions:
 *       - dipole_moments: num_particles * dimensions
 *       - field_gradients: num_particles * dimensions * dimensions
 *       - forces_array: num_particles * dimensions
 * 
 * Example:
 * @code
 * std::vector<std::complex<double>> dipole_moments = { ... };
 * std::vector<std::complex<double>> field_gradients = { ... };
 * std::vector<double> forces_array(num_particles * dimensions);
 * calculateOpticalForces(dipole_moments, field_gradients, epsilon_m, num_particles, dimensions, forces_array);
 * @endcode
 */
 
#ifndef OPTICAL_FORCES_CALC_DA_H
#define OPTICAL_FORCES_CALC_DA_H

#include <vector>
#include <complex>
#include <stdexcept> // For throwing exceptions

// Function to calculate optical forces in the dipolar approximation
void calculateOpticalForces(
    const std::vector<std::complex<double>>& dipole_moments,  // Dipole moments
    const std::vector<std::complex<double>>& field_gradients, // Field gradients
    double epsilon_m,                                         // Medium permittivity
    int num_particles,                                        // Number of particles
    int dimensions,                                          // Dimensions of the system
    std::vector<double>& forces_array                        // Array to store calculated forces
) {
    // Check the size of the input vectors
    if (dipole_moments.size() != static_cast<size_t>(num_particles * dimensions)) {
        throw std::invalid_argument("The size of dipole_moments does not match num_particles * dimensions.");
    }
    if (field_gradients.size() != static_cast<size_t>(num_particles * dimensions * dimensions)) {
        throw std::invalid_argument("The size of field_gradients does not match num_particles * dimensions * dimensions.");
    }

    // Check the size of the forces_array
    if (forces_array.size() != static_cast<size_t>(num_particles * dimensions)) {
        throw std::invalid_argument("The size of forces_array must be num_particles * dimensions.");
    }

    // Initialize the forces_array to zero
    std::fill(forces_array.begin(), forces_array.end(), 0.0);

    // Calculate forces for each particle
    for (int i = 0; i < num_particles; i++) {
        for (int j = 0; j < dimensions; j++) {
            // Calculate the j-th component of the force for particle i
            for (int k = 0; k < dimensions; k++) {
                // F_j = (ε_m / 2) Re{p · ∂_jE*}
                forces_array[i * dimensions + j] += (epsilon_m / 2.0) * 
                    std::real(dipole_moments[i * dimensions + k] * 
                    std::conj(field_gradients[i * dimensions * dimensions + j * dimensions + k]));
            }
        }
    }
}

#endif // OPTICAL_FORCES_CALC_DA_H
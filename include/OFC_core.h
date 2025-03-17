#pragma once
#include <vector>
#include <complex>

namespace OFC{

/**
 * @brief Optical forces calculation using the dipolar approximation.
 * 
 * This function contains the implementation of the `calculateOpticalForces` function,
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

void calculateOpticalForces(
    const std::vector<std::complex<double>>& dipole_moments,    // Dipole moments
    const std::vector<std::complex<double>>& field_gradients,   // Field gradients
    double epsilon_m,                                           // Medium permittivity
    int num_particles,                                          // Number of particles
    int dimensions,                                             // Dimensions of the system
    std::vector<double>& forces_array);                         // Array to store calculated forces

} // namespace OFC



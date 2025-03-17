#include "core.h"

namespace OFC {

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

} // namespace OFC



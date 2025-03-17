#include <gtest/gtest.h>
#include "OFC_core.h"
using namespace OFC;

TEST(CoreLibrary, SanityCheck) {
    // Test the sanity of the core library
    std::vector<std::complex<double>> dipole_moments = {1.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    std::vector<std::complex<double>> field_gradients = {1.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    double epsilon_m = 1.0;
    int num_particles = 1;
    int dimensions = 3;
    std::vector<double> forces_array(3, 0.0);
    calculateOpticalForces(dipole_moments, field_gradients, epsilon_m, num_particles, dimensions, forces_array);
    EXPECT_EQ(forces_array[0], 0.5);
    EXPECT_EQ(forces_array[1], 0.0);
    EXPECT_EQ(forces_array[2], 0.0);
}


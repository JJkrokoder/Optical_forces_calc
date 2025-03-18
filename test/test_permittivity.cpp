#include <gtest/gtest.h>
#include "dielectric_optcoeff.h"
using namespace dioptco;

// Tests for permittivity class construction

TEST(Permittivity, DefaultConstructor) {
    Permittivity perm("gold");
    EXPECT_EQ(perm.material, "gold");
}

TEST(Permittivity, getPermittivity) {
    Permittivity perm("gold");
    // Obtain gold permittivity
    std::complex<double> epsilon = perm.getPermittivity(1000);
    // Check real part
    EXPECT_NEAR(epsilon.real(), 9.0, 1e-6);
    // Check imaginary part
    EXPECT_NEAR(epsilon.imag(), 0.0, 1e-6);

}




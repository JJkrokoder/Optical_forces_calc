#include <gtest/gtest.h>
#include "dielectric_optcoeff.h"
using namespace dioptco;

// Tests for permittivity class construction

TEST(Permittivity, DefaultConstructor) {
    Permittivity perm("gold");
    EXPECT_EQ(perm.material, "gold");
}

TEST(Permittivity, getgoldPermittivity) {

    Permittivity perm("gold");

    double wavelength = 200;
    double energy = 1239.842/wavelength;
    double eb = 9;
    double ep = 9;
    double et = 0.05;

    std::complex<double> epsilon = perm.getPermittivity(wavelength); 
    // Check real part
    EXPECT_NEAR(epsilon.real(), eb-ep*ep/(energy*energy+et*et), 1e-6);
    // Check imaginary part
    EXPECT_NEAR(epsilon.imag(), ep*ep*et/(energy*energy+et*et)/energy, 1e-6);

}




#include <gtest/gtest.h>
#include "dielectric_optcoeff.h"
using namespace dioptco;

// Tests for permittivity class construction

TEST(Permittivity, DefaultConstructor) {
    Permittivity perm("gold");
    EXPECT_EQ(perm.material, "gold");
}




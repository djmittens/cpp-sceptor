#include <iostream>
#include <gtest/gtest.h>

#include "MathFunctions.h"


TEST(MySqrt, DoestStuff) {
    auto a = mysqrt(4.0);

    EXPECT_EQ(a, 4);
}
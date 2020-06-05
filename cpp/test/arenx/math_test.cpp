#include "math.hpp"

#include "gtest/gtest.h"

using namespace ::testing;
using namespace ::std;
using namespace ::arenx;

namespace arenx::math_test
{

    TEST(Math, getModularInverse)
    {
        vector<vector<int>> cases = {

            {3, 29, 10},
            {301, 1000000007, 770764125},
        };

        for (auto &c : cases)
        {
            int actual = getModularInverse(c[0], c[1]);
            EXPECT_EQ(actual, c[2]);
        }
    }

} // namespace arenx::math_test
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

    TEST(Math, getModularInverse_randomInput)
    {

        auto brutforce = [](int n, int prime) {
            n %= prime;
            int64_t m = prime / n * n;
            while (m % prime != 1)
            {
                m += n;
            }

            return m / n;
        };

        auto isPrime = [](int n) {
            for (int i = 2; i <= n / 2; ++i)
            {
                if (n % i == 0)
                {
                    return false;
                }
            }
            return true;
        };

        int count = 1000;

        while (count-- > 0)
        {

            int n = 2 + (rand() % 1000);
            int prime = n + 1 + (rand() % 100000);

            while (!isPrime(prime))
            {
                prime = n + 1 + (rand() % 100000);
            }

            int expect = brutforce(n, prime);
            int actual = getModularInverse(n, prime);

            ASSERT_EQ(actual, expect) << "n=" << n << " prime=" << prime;
        }
    }

} // namespace arenx::math_test
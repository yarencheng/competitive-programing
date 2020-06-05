#include "math.hpp"

using namespace ::arenx;

int ::arenx::getModularInverse(int n, int prime)
{
    int64_t dp[n + 1];
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[prime % i] * (prime - prime / i) % prime;
    }

    return dp[n];
}
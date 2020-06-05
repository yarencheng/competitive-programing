#include "string.hpp"
#include "gtest/gtest.h"
#include "test_utils.hpp"

using namespace ::testing;
using namespace ::std;
using namespace ::arenx;

namespace arenx::string_test
{

    TEST(String, KMPFind)
    {
        vector<tuple<string, string, int>> cases = {

            {"abcaby", "abxabcabcaby", 6},
            {"bbbacddceeb", "ceebbbbacddceebbbbacdd", 4}};

        for (auto &c : cases)
        {
            auto [pattern, text, index] = c;
            int actual = KMPFind(pattern, text);
            EXPECT_EQ(actual, index) << "pattern: " << pattern << ", text: " << text;
        }
    }

    TEST(String, KMPFind_useRandomString)
    {
        int count = 10000;

        while (count-- > 0)
        {
            string pattern = randomAlphaNumberString(rand() % 10);
            string text = randomAlphaNumberString(rand() % 100);

            int expect = text.find(pattern);
            int actual = KMPFind(pattern, text);

            EXPECT_EQ(actual, expect) << "pattern: " << pattern << ", text: " << text;
        }
    }
} // namespace arenx::string_test
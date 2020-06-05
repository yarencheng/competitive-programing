#include "string.hpp"

using namespace ::std;
using namespace ::arenx;

int ::arenx::KMPFind(const string &pattern, const string &text)
{

    int shift[pattern.size()];
    shift[0] = 0;

    int j = 0;
    for (int i = 1; i < pattern.size(); i++)
    {

        while (j > 0 && pattern[j] != pattern[i])
        {
            j = shift[j - 1];
        }

        if (pattern[j] == pattern[i])
        {
            shift[i] = j + 1;
            j++;
        }
        else
        {
            shift[i] = 0;
        }
    }

    int p = 0;

    for (int t = 0; t < text.size(); t++)
    {

        if (p == pattern.size())
        {
            return t - p;
        }

        while (p > 0 && text[t] != pattern[p])
        {
            p = shift[p - 1];
        }

        if (text[t] == pattern[p])
        {
            p++;
        }
    }

    return p == pattern.size() ? text.size() - p : -1;
}
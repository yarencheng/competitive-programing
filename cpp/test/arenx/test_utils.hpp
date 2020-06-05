#include "cpp_common_header.hpp"

using namespace ::std;

string randomAlphaNumberString(int len)
{
    string c = "0123456789abcdefghijklmnopqrstuvwxyz";

    string ret;
    ret.resize(len);

    for (int i = 0; i < len; i++)
    {
        ret[i] = c[rand() % c.size()];
    }

    return ret;
}
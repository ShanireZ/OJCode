#include <algorithm>
#include <iostream>
using namespace std;
extern "C" int Seniorious(int);
extern "C" int Chtholly(int n, int c)
{
    int l = 1, r = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int res = Seniorious(mid);
        if (res == -1)
        {
            l = mid + 1;
        }
        else if (res == 1)
        {
            r = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return r;
}
// TAG: 交互题 二分
#include <algorithm>
#include <iostream>
using namespace std;
long long x, y, l = 1, r = 1e18;
bool check(long long num)
{
    __int128 base = 1, res = 0;
    while (num / base)
    {
        long long high = num / base / 10;
        long long cur = num / base % 10;
        long long low = num % base;
        if (x == 0)
        {
            if (high == 0)
            {
                break;
            }
            if (cur == 0)
            {
                res += (high - 1) * base + low + 1;
            }
            else
            {
                res += high * base;
            }
        }
        else
        {
            if (cur < x)
            {
                res += high * base;
            }
            else if (cur == x)
            {
                res += high * base + low + 1;
            }
            else
            {
                res += (high + 1) * base;
            }
        }
        base *= 10;
    }
    return res <= y;
}
int main()
{
    cin >> x >> y;
    while (l <= r)
    {
        long long mid = (l + r) / 2;
        check(mid) ? l = mid + 1 : r = mid - 1;
    }
    cout << r << endl;
    return 0;
}
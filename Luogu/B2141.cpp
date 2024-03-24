#include <algorithm>
#include <iostream>
using namespace std;
long long zh(long long x, long long jz)
{
    long long tot = 0, base = 1;
    while (x)
    {
        if (x % 10 >= jz)
        {
            return -1;
        }
        tot += x % 10 * base;
        x /= 10, base *= jz;
    }
    return tot;
}
int main()
{
    long long p, q, r;
    cin >> p >> q >> r;
    for (int i = 2; i <= 16; i++)
    {
        long long pp = zh(p, i), qq = zh(q, i), rr = zh(r, i);
        if (pp != -1 && qq != -1 && rr != -1 && pp * qq == rr)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}
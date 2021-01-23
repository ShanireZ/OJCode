#include <cstdio>
#include <algorithm>
using namespace std;
int read() //快读
{
    char ch = getchar();
    while ((ch > '9' || ch < '0') && ch != '-')
    {
        ch = getchar();
    }
    int t = 1, n = 0;
    if (ch == '-')
    {
        t = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        n = n * 10 + ch - '0';
        ch = getchar();
    }
    return n * t;
}
long long num[400005];
int main()
{
    int t = read();
    for (int i = 1; i <= t; i++)
    {
        long long q = read(), mod = read();
        int m = 1;
        while (m <= q)
        {
            m *= 2;
        }
        fill(num, num + 4 * q + 1, 1);
        for (int i = m + 1; i <= m + q; i++)
        {
            long long op = read(), x = read(), pos;
            if (op == 1)
            {
                num[i] = x % mod;
                pos = i;
            }
            else //* op2时不能除 因为有取余 除了会出现结果是0的情况
            {
                num[m + x] = 1;
                pos = m + x;
            }
            pos /= 2;
            while (pos)
            {
                num[pos] = num[pos * 2] * num[pos * 2 + 1] % mod;
                pos /= 2;
            }
            printf("%lld\n", num[1]);
        }
    }
    return 0;

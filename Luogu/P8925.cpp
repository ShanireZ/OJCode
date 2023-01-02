#include <iostream>
using namespace std;
long long read();
int main()
{
    long long t = read(), l = read(), r = read();
    l *= 2, r *= 2;
    for (int i = 1; i <= t; i++)
    {
        char opt = getchar();
        while (opt != 'L' && opt != 'R')
        {
            opt = getchar();
        }
        long long x = read();
        if (opt == 'L')
        {
            printf("-%lld\n", l + x / 2 * r + (x - 1) / 2 * l);
        }
        else
        {
            printf("%lld\n", r + x / 2 * l + (x - 1) / 2 * r);
        }
    }
    return 0;
}
long long read()
{
    long long ans = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}
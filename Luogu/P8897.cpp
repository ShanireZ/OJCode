#include <algorithm>
#include <iostream>
using namespace std;
long long c[100005], read();
int main()
{
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        c[i] = read();
    }
    sort(c + 1, c + 1 + n);
    long long p = 0, tot = 0;
    for (int i = 1; i <= n; i++)
    {
        if (c[i] * (n - i + 1) > tot)
        {
            tot = c[i] * (n - i + 1), p = c[i];
        }
    }
    printf("%lld %lld\n", tot, p);
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
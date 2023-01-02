#include <iostream>
using namespace std;
long long a[1000005], b[1000005], read();
void print(__int128);
int main()
{
    ios::sync_with_stdio(false);
    __int128 tot = 0, tot2 = 0;
    long long n = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    for (int i = 1; i <= n; i++)
    {
        b[i] = read();
        tot += b[i], tot2 += b[i] * b[i];
    }
    __int128 ans = n * tot2 - tot * tot;
    for (int i = 1; i <= n; i++)
    {
        tot = tot - b[i] + a[i], tot2 = tot2 - b[i] * b[i] + a[i] * a[i];
        ans = max(ans, n * tot2 - tot * tot);
    }
    print(ans);
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
void print(__int128 x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x < 10)
    {
        putchar(x + 48);
        return;
    }
    print(x / 10);
    putchar(x % 10 + 48);
}
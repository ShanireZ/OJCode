#include <iostream>
using namespace std;
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}
int a[500005];
long long M(int l, int r)
{
    long long ans = 0;
    if (r - l <= 5)
    {
        for (int i = l; i <= r; i++)
        {
            ans = max(ans, (long long)a[i]);
        }
    }
    else
    {
        ans = a[(l + r) / 2] - 1 + M(l, (l + r) / 2) % max(M((l + r) / 2 + 1, r), 7ll);
    }
    return ans;
}
int main()
{
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    printf("%lld\n", M(1, n));
    return 0;
}
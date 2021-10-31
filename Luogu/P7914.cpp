#include <cstdio>
#include <algorithm>
using namespace std;
#define mod 1000000007
#define maxn 505
long long f[maxn][maxn], qzh[maxn][maxn], v[maxn][maxn];
int n, k;
char s[maxn];
bool check(int p, char c)
{
    if (p < 1 || p > n)
    {
        return false;
    }
    return (s[p] == c || s[p] == '?');
}
int main()
{
    scanf("%d %d %s", &n, &k, s + 1);
    for (int i = 2; i <= n; i++)
    {
        f[i][i - 1] = 1;
    }
    for (int l = n; l >= 1; l--)
    {
        for (int r = l; r <= n; r++)
        {
            if (check(l, '(') && check(r, ')'))
            {
                f[l][r] = f[l + 1][r - 1]; //(A)
                for (int p = r - 1; p >= max(r - k, l + 2) && check(p, '*'); p--)
                {
                    f[l][r] = (f[l][r] + f[l + 1][p - 1]) % mod; //(AS)
                }
                for (int p = l + 1; p <= min(l + k, r - 1) && check(p, '*'); p++)
                {
                    f[l][r] = (f[l][r] + f[p + 1][r - 1]) % mod; //(SA)
                }
            }
            qzh[l][r] = v[l][r] = f[l][r];
            for (int p = r; p >= max(r - k + 1, l) && check(p, '*'); p--) //AS前缀和
            {
                qzh[l][r] = (qzh[l][r] + v[l][p - 1]) % mod;
            }
            for (int p = l; p < r; p++) //ASB
            {
                f[l][r] = (f[l][r] + (qzh[l][p] * f[p + 1][r]) % mod) % mod;
            }
        }
    }
    printf("%lld\n", f[1][n]);
    return 0;
}
#include <cmath>
#include <iostream>
using namespace std;
#define MOD 1000000007
#define MX 100000000
bool vis[MX + 5];
int prim[6000005], power[6000005], pos;
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
int main()
{
    for (int i = 2; i <= MX; i++)
    {
        if (vis[i] == 0)
        {
            prim[++pos] = i;
        }
        for (int j = 1; j <= pos && i * prim[j] <= MX; j++)
        {
            vis[i * prim[j]] = 1;
            if (i % prim[j] == 0)
            {
                break;
            }
        }
    }
    power[0] = 1;
    for (int i = 1; i <= pos; i++)
    {
        power[i] = power[i - 1] * 2 % MOD;
    }
    int t = read();
    while (t--)
    {
        long long k = read();
        int p = read(), q = read(), cnt = 0;
        for (int i = 1; i <= pos && k >= 1ll * prim[i] * prim[i]; i++)
        {
            cnt += (k % prim[i] == 0);
            while (k % prim[i] == 0)
            {
                k /= prim[i];
            }
        }
        cnt += (k > 1);
        printf("%d\n", 1ll * power[cnt] * (q - p + 1) % MOD);
    }
    return 0;
}
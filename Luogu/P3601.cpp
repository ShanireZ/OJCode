#include <algorithm>
#include <iostream>
using namespace std;
#define MX 1000005
#define MOD 666623333
long long l, r, ans, pos, vis[MX], prim[MX], fi[MX], ex[MX];
int main()
{
    cin >> l >> r;
    for (long long i = l; i <= r; i++)
    {
        fi[i - l] = ex[i - l] = i;
    }
    for (long long i = 2; i <= 1000000; i++)
    {
        if (vis[i] == 0)
        {
            prim[++pos] = i;
        }
        for (long long j = 1; j <= pos && prim[j] * i <= 1000000; j++)
        {
            vis[prim[j] * i] = 1;
            if (i % prim[j] == 0)
            {
                break;
            }
        }
    }
    // 一個數的質因數最多有一個大於sqrt(n)，將其存到ex陣列裡
    // 其餘質因數暴力枚舉，用歐拉定理求出fi
    for (long long i = 1; i <= pos && prim[i] * prim[i] <= r; i++)
    {
        long long st = (l % prim[i] == 0 ? l : l / prim[i] * prim[i] + prim[i]);
        for (long long j = st; j <= r; j += prim[i])
        {
            long long p = j - l;
            fi[p] = fi[p] / prim[i] * (prim[i] - 1);
            while (ex[p] % prim[i] == 0)
            {
                ex[p] /= prim[i];
            }
        }
    }
    for (long long i = l; i <= r; i++)
    {
        long long p = i - l;
        if (ex[p] != 1)
        {
            fi[p] = fi[p] / ex[p] * (ex[p] - 1);
        }
        ans = (ans + i - fi[p]) % MOD;
    }
    cout << ans << endl;
    return 0;
}
// TAG: 質數 歐拉定理 歐拉篩
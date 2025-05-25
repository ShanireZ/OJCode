#include <algorithm>
#include <iostream>
using namespace std;
long long dp[1005], prim[1005], vis[1005], pos, n;
int main()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            prim[++pos] = i;
        }
        for (int j = 1; j <= pos && prim[j] * i <= n; j++)
        {
            vis[prim[j] * i] = 1;
            if (i % prim[j] == 0)
            {
                break;
            }
        }
    }
    dp[0] = 1;
    for (int i = 1; i <= pos; i++)
    {
        for (int j = prim[i]; j <= n; j++)
        {
            dp[j] += dp[j - prim[i]];
        }
    }
    cout << dp[n] << endl;
    return 0;
}
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int n, m, k, dp[2000005];
int main()
{
    cin >> n >> m >> k;
    memset(dp, 0x3f, sizeof(dp)), dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int sta = 0;
        for (int j = 1; j <= k; j++)
        {
            int x;
            cin >> x;
            sta = sta | (1 << (x - 1));
        }
        for (int pre = (1 << m) - 1; pre >= 0; pre--)
        {
            dp[pre | sta] = min(dp[pre | sta], dp[pre] + 1);
        }
    }
    if (dp[(1 << m) - 1] == 0x3f3f3f3f)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dp[(1 << m) - 1] << endl;
    }
    return 0;
}
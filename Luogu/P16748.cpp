#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int sum[35], dp[1505], n, k, p, T;
int main()
{
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> n >> k >> p;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                cin >> sum[j];
                sum[j] += sum[j - 1];
            }
            for (int j = n * k; j > 0; j--)
            {
                for (int x = 1; x <= k; x++)
                {
                    if (j - x >= 0)
                    {
                        dp[j] = max(dp[j], dp[j - x] + sum[x]);
                    }
                }
            }
        }
        cout << "Case #" << t << ": " << dp[p] << endl;
        memset(dp, 0, sizeof(dp));
    }
    return 0;
}
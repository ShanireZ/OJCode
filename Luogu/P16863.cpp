#include <algorithm>
#include <iostream>
using namespace std;
int T, n, k, b[5005], dp[1000005];
int main()
{
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
        }
        int ans = 1e9;
        for (int i = 1; i <= k; i++)
        {
            dp[i] = 1e9;
        }
        for (int i = 1; i <= n; i++)
        {
            int tot = 0;
            for (int j = i; j <= n; j++)
            {
                tot += b[j];
                if (tot > k)
                {
                    break;
                }
                ans = min(ans, dp[k - tot] + j - i + 1);
            }
            tot = 0;
            for (int j = i; j >= 1; j--)
            {
                tot += b[j];
                if (tot > k)
                {
                    break;
                }
                dp[tot] = min(dp[tot], i - j + 1);
            }
        }
        cout << "Case #" << t << ": " << (ans == 1e9 ? -1 : ans) << endl;
    }
    return 0;
}
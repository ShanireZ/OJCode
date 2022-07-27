#include <cstring>
#include <iostream>
using namespace std;
int dp[255][255];
int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        dp[i][i] = x, ans = max(ans, x);
    }
    for (int len = 2; len <= n; len++)
    {
        for (int l = 1; l <= n; l++)
        {
            int r = l + len - 1;
            if (r > n)
            {
                break;
            }
            for (int mid = l; mid < r; mid++)
            {
                if (dp[l][mid] != dp[mid + 1][r])
                {
                    continue;
                }
                dp[l][r] = max(dp[l][r], max(dp[l][mid], dp[mid + 1][r]) + 1);
            }
            ans = max(ans, dp[l][r]);
        }
    }
    cout << ans << endl;
    return 0;
}
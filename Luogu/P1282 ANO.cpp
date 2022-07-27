#include <cstring>
#include <iostream>
using namespace std;
int dp[6005], a[1005], b[1005];
int main()
{
    int n, tot = 0, tota = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        tot += a[i] + b[i], tota += a[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0, dp[tota] = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = b[i] - a[i];
        if (x < 0)
        {
            for (int j = n; j <= n * 6; j++)
            {
                if (dp[j] != 0x3f3f3f3f)
                {
                    dp[j + x] = min(dp[j + x], dp[j] + 1);
                }
            }
        }
        else
        {
            for (int j = n * 6; j >= n; j--)
            {
                if (dp[j] != 0x3f3f3f3f)
                {
                    dp[j + x] = min(dp[j + x], dp[j] + 1);
                }
            }
        }
    }
    int ans = 0x3f3f3f3f, r = 0x3f3f3f3f;
    for (int i = n; i <= n * 6; i++)
    {
        if (dp[i] == 0x3f3f3f3f)
        {
            continue;
        }
        if (ans > abs(tot - i * 2))
        {
            ans = abs(tot - i * 2);
            r = dp[i];
        }
        else if (ans == abs(tot - i * 2))
        {
            r = min(r, dp[i]);
        }
    }
    cout << r << endl;
    return 0;
}
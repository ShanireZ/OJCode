#include <cstring>
#include <iostream>
using namespace std;
int dp[1005][6005];
int main()
{
    int n, tot = 0;
    cin >> n;
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        tot += a + b;
        for (int s = i; s <= 6000; s++)
        {
            if (s >= a)
            {
                dp[i][s] = min(dp[i][s], dp[i - 1][s - a]);
            }
            if (s >= b)
            {
                dp[i][s] = min(dp[i][s], dp[i - 1][s - b] + 1);
            }
        }
    }
    int ans = 0x3f3f3f3f, r = 0x3f3f3f3f;
    for (int i = n; i <= 6000; i++)
    {
        if (dp[n][i] == 0x3f3f3f3f)
        {
            continue;
        }
        if (ans > abs(tot - i * 2))
        {
            ans = abs(tot - i * 2), r = dp[n][i];
        }
        else if (ans == abs(tot - i * 2))
        {
            r = min(r, dp[n][i]);
        }
    }
    cout << r << endl;
    return 0;
}

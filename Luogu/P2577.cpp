#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
struct Node
{
    int wait, eat;
    bool operator<(const Node &oth) const
    {
        return eat > oth.eat;
    }
};
Node ns[205];
int dp[205][40005], qz[205];
int main()
{
    int n, ans = 0x3f3f3f3f;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].wait >> ns[i].eat;
    }
    sort(ns + 1, ns + 1 + n);
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        qz[i] = qz[i - 1] + ns[i].wait;
        for (int j = 0; j <= qz[i]; j++)
        {
            if (j >= ns[i].wait)
            {
                dp[i][j] = min(dp[i][j], max(dp[i - 1][j - ns[i].wait], j + ns[i].eat));
            }
            dp[i][j] = min(dp[i][j], max(dp[i - 1][j], qz[i] - j + ns[i].eat));
        }
    }
    for (int i = 0; i <= qz[n]; i++)
    {
        ans = min(ans, dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}
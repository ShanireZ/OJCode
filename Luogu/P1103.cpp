#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
struct Book
{
    int h, w;
    bool operator<(const Book oth) const
    {
        return h < oth.h;
    }
};
Book bs[105];
int dp[105][105]; // dp[i][j] 选了i本且最后一本是第j本
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> bs[i].h >> bs[i].w;
    }
    sort(bs + 1, bs + 1 + n);
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        dp[1][i] = 0;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = i; j > 1; j--) // 选了j本
        {
            for (int k = i - 1; k >= 1; k--) // 最后一本是第k本
            {
                dp[j][i] = min(dp[j][i], dp[j - 1][k] + abs(bs[i].w - bs[k].w));
            }
        }
    }
    int ans = 0x3f3f3f3f;
    for (int i = n - k; i <= n; i++)
    {
        ans = min(ans, dp[n - k][i]);
    }
    cout << ans << endl;
    return 0;
}
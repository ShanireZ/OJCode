#include <iostream>
using namespace std;
struct Node
{
    int cnt, t;
};
Node dp[105][105];
struct Girl
{
    int rmb, rp, t;
};
Girl gs[105];
int main()
{
    int n, m, r;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> gs[i].rmb >> gs[i].rp >> gs[i].t;
    }
    cin >> m >> r;
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= gs[i].rmb; j--)
        {
            for (int k = r; k >= gs[i].rp; k--)
            {
                if (dp[j - gs[i].rmb][k - gs[i].rp].cnt + 1 > dp[j][k].cnt)
                {
                    dp[j][k].cnt = dp[j - gs[i].rmb][k - gs[i].rp].cnt + 1;
                    dp[j][k].t = dp[j - gs[i].rmb][k - gs[i].rp].t + gs[i].t;
                }
                else if (dp[j - gs[i].rmb][k - gs[i].rp].cnt + 1 == dp[j][k].cnt)
                {
                    dp[j][k].t = min(dp[j - gs[i].rmb][k - gs[i].rp].t + gs[i].t, dp[j][k].t);
                }
            }
        }
    }
    cout << dp[m][r].t << endl;
    return 0;
}
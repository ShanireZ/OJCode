#include <iostream>
#include <vector>
using namespace std;
struct Good
{
    int v, p, q, tot;
};
Good gs[100];
int chs[100][5], dp[32005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> gs[i].v >> gs[i].p >> gs[i].q;
        gs[i].tot = gs[i].v * gs[i].p;
        if (gs[i].q)
        {
            int id = ++chs[gs[i].q][0];
            chs[gs[i].q][id] = i;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (gs[i].q)
        {
            continue;
        }
        int c1 = chs[i][1], c2 = chs[i][2];
        int v1 = gs[c1].v, v2 = gs[c2].v, v = gs[i].v;
        int tot1 = gs[c1].tot, tot2 = gs[c2].tot, tot = gs[i].tot;
        for (int j = n; j >= v; j--)
        {
            dp[j] = max(dp[j - v] + tot, dp[j]);
            if (j >= v + v1)
            {
                dp[j] = max(dp[j - v - v1] + tot + tot1, dp[j]);
            }
            if (j >= v + v2)
            {
                dp[j] = max(dp[j - v - v2] + tot + tot2, dp[j]);
            }
            if (j >= v + v1 + v2)
            {
                dp[j] = max(dp[j - v - v1 - v2] + tot + tot1 + tot2, dp[j]);
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}
#include <algorithm>
#include <iostream>
using namespace std;
int dp[32005], dpn[32005], fj[65][3], zl[65], jz[65], n, m;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int v, p, q;
        cin >> v >> p >> q;
        zl[i] = v, jz[i] = v * p;
        if (q != 0)
        {
            fj[q][2] = fj[q][1];
            fj[q][1] = i, fj[i][0] = 1;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (fj[i][0] == 1)
        {
            continue;
        }
        int cost[5] = {zl[i]}, val[5] = {jz[i]};
        int id1 = fj[i][1], id2 = fj[i][2], pos = 0;
        if (id1)
        {
            cost[1] = zl[i] + zl[id1], val[1] = jz[i] + jz[id1];
            pos = 1;
        }
        if (id2)
        {
            cost[2] = zl[i] + zl[id2], val[2] = jz[i] + jz[id2];
            cost[3] = zl[i] + zl[id1] + zl[id2], val[3] = jz[i] + jz[id1] + jz[id2];
            pos = 3;
        }
        for (int j = 0; j <= pos; j++) //! 组内所有物品
        {
            for (int k = n; k >= cost[j]; k--) //! 所有花费(重量)
            {
                dpn[k] = max(dpn[k], dp[k - cost[j]] + val[j]);
            }
        }
        for (int k = 1; k <= n; k++)
        {
            dp[k] = dpn[k];
        }
    }
    cout << dp[n] << endl;
    return 0;
}
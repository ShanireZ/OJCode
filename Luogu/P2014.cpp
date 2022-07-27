#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
vector<int> chs[305];
int s[305], k[305], dp[305], gs[305][305], n, m;
void dfs(int now, int deep, int fa)
{
    for (int i = deep; i <= m; i++)
    {
        gs[now][i] = gs[fa][i - 1] + s[now];
    }
    for (int i = 0; i < chs[now].size(); i++)
    {
        int ch = chs[now][i];
        dfs(ch, deep + 1, now);
        for (int j = deep + 1; j <= m; j++)
        {
            gs[now][j] = max(gs[now][j], gs[ch][j]);
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i] >> s[i];
        if (k[i] != 0)
        {
            chs[k[i]].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (k[i] != 0)
        {
            continue;
        }
        dfs(i, 1, 0);
        for (int j = m; j >= 1; j--) // dp范围
        {
            for (int k = 1; k <= j; k++) // 当前分支的数量
            {
                dp[j] = max(dp[j], dp[j - k] + gs[i][k]);
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}
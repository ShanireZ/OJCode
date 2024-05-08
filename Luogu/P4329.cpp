#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
double p[25][25], maxp[25], all = 1, ans;
int n, vis[25];
void dfs(int now, double last, double np)
{
    if (now == n + 1)
    {
        ans = max(ans, np);
        return;
    }
    if (np * last <= ans)
    {
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
        {
            continue;
        }
        vis[i] = 1;
        dfs(now + 1, last / maxp[now], np * p[now][i]);
        vis[i] = 0;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> p[i][j];
            p[i][j] /= 100;
            maxp[i] = max(maxp[i], p[i][j]);
        }
        all *= maxp[i];
        // 此处可以让所有人的任务按概率从大到小排序,优先选择概率大的任务,加快以后剪枝的速度
    }
    dfs(1, all, 1);
    cout << fixed << setprecision(6) << ans * 100 << endl;
    return 0;
}
// TAG: 状态压缩 DP A*搜索 启发式
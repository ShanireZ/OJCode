#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
#define MX 100005
vector<int> to[MX];
int anc[MX][20], maxd[MX][20], mind[MX][20], cmaxd[MX][20], cmind[MX][20];
int deep[MX], dfn[MX], n, q, pos;
void dfs(int now)
{
    maxd[now][0] = mind[now][0] = ++pos;
    cmind[now][0] = n + 1, dfn[pos] = now;
    for (int i = 1; i < 17; i++)
    {
        anc[now][i] = anc[anc[now][i - 1]][i - 1];
    }
    for (int nxt : to[now])
    {
        deep[nxt] = deep[now] + 1;
        dfs(nxt);
    }
}
int lca(int a, int b)
{
    if (deep[a] < deep[b])
    {
        swap(a, b);
    }
    for (int i = 16; i >= 0; i--)
    {
        if (deep[anc[a][i]] >= deep[b])
        {
            a = anc[a][i];
        }
    }
    if (a == b)
    {
        return a;
    }
    for (int i = 16; i >= 0; i--)
    {
        if (anc[a][i] != anc[b][i])
        {
            a = anc[a][i], b = anc[b][i];
        }
    }
    return anc[a][0];
}
int main()
{
    cin >> n >> q;
    for (int i = 2; i <= n; i++)
    {
        cin >> anc[i][0];
        to[anc[i][0]].push_back(i);
    }
    dfs(1);
    for (int j = 1; j < 17; j++) // 找到所有编号区间dfn的 最大 次大 最小 次小
    {
        for (int i = 1; i <= n; i++)
        {
            int len = 1 << (j - 1), all[4];
            all[0] = maxd[i][j - 1], all[1] = maxd[i + len][j - 1];
            all[2] = cmaxd[i][j - 1], all[3] = cmaxd[i + len][j - 1];
            sort(all, all + 4), maxd[i][j] = all[3], cmaxd[i][j] = all[2];
            all[0] = mind[i][j - 1], all[1] = mind[i + len][j - 1];
            all[2] = cmind[i][j - 1], all[3] = cmind[i + len][j - 1];
            sort(all, all + 4), mind[i][j] = all[0], cmind[i][j] = all[1];
        }
    }
    while (q--) // dfn最大肯定在最右边 dfn最小肯定是最左边的祖先 尝试去掉dfn最大或最小
    {
        int l, r;
        cin >> l >> r;
        int x = log2(r - l + 1);
        int len = 1 << x, all[4];
        all[0] = maxd[l][x], all[1] = maxd[r - len + 1][x];
        all[2] = cmaxd[l][x], all[3] = cmaxd[r - len + 1][x];
        sort(all, all + 4);
        int dr = all[3], cdr = (all[3] == all[2] ? all[1] : all[2]); // 次大有陷阱
        all[0] = mind[l][x], all[1] = mind[r - len + 1][x];
        all[2] = cmind[l][x], all[3] = cmind[r - len + 1][x];
        sort(all, all + 4);
        int dl = all[0], cdl = (all[0] == all[1] ? all[2] : all[1]);
        int lca1 = lca(dfn[dl], dfn[cdr]), lca2 = lca(dfn[dr], dfn[cdl]);
        if (deep[lca1] > deep[lca2])
        {
            cout << dfn[dr] << " " << deep[lca1] << endl;
        }
        else
        {
            cout << dfn[dl] << " " << deep[lca2] << endl;
        }
    }
    return 0;
}
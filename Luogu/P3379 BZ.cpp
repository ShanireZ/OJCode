#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
#define MX 500005
vector<int> to[MX];
int n, m, root, dp[MX], anc[MX][20];
void init(int now, int deep)
{
    dp[now] = deep;
    for (int i = 1; i <= log2(deep); i++)
    {
        anc[now][i] = anc[anc[now][i - 1]][i - 1];
    }
    for (int i = 0; i < to[now].size(); i++)
    {
        int nxt = to[now][i];
        if (nxt != anc[now][0])
        {
            anc[nxt][0] = now;
            init(nxt, deep + 1);
        }
    }
}
int lca(int x, int y)
{
    if (dp[x] < dp[y])
    {
        swap(x, y);
    }
    while (dp[x] != dp[y])
    {
        int ex = log2(dp[x] - dp[y]);
        x = anc[x][ex];
    }
    if (x == y)
    {
        return x;
    }
    for (int i = log2(dp[x]); i >= 0; i--)
    {
        if (anc[x][i] != anc[y][i])
        {
            x = anc[x][i], y = anc[y][i];
        }
    }
    return anc[x][0];
}
int main()
{
    cin >> n >> m >> root;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        to[a].push_back(b), to[b].push_back(a);
    }
    init(root, 1);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << endl;
    }
    return 0;
}
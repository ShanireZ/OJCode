#include <iostream>
#include <vector>
using namespace std;
int n, m, c;
vector<int> es[505]; //! es[i] 左边的点i连接到了右边的哪些点
int usd[505], b[505];
bool dfs(int now, int tag)
{
    if (usd[now] == tag)
    {
        return 0;
    }
    usd[now] = tag;
    for (int i = 0; i < es[now].size(); i++)
    {
        int to = es[now][i];
        if (b[to] == 0 || dfs(b[to], tag))
        {
            b[to] = now;
            return 1;
        }
    }
    return 0;
}
int main()
{
    cin >> n >> m >> c;
    for (int i = 1; i <= c; i++)
    {
        int u, v;
        cin >> u >> v;
        es[u].push_back(v);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt += dfs(i, i);
    }
    cout << cnt << endl;
    return 0;
}
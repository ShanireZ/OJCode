#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
queue<pair<int, int>> q;
vector<int> to[200005];
int n, m, cnt, vis[200005];
void bfs(int x)
{
    q.emplace(make_pair(x, 0)), vis[x] = 1;
    while (q.size())
    {
        int now = q.front().first, from = q.front().second;
        q.pop();
        for (int nxt : to[now])
        {
            if (nxt == from)
            {
                continue;
            }
            if (vis[nxt] == 0)
            {
                vis[nxt] = 1, q.emplace(make_pair(nxt, now));
            }
            else
            {
                cnt++;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].emplace_back(v), to[v].emplace_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            bfs(i);
        }
    }
    cout << cnt / 2 << endl;
    return 0;
}
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, m, dis[20005];
vector<int> to[20005];
queue<int> q;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].emplace_back(v), to[v].emplace_back(u);
    }
    fill(dis, dis + n + 1, 0x3f3f3f3f);
    dis[1] = 0, q.emplace(1);
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (int nxt : to[now])
        {
            if (dis[nxt] == 0x3f3f3f3f)
            {
                dis[nxt] = dis[now] + 1, q.emplace(nxt);
            }
        }
    }
    int p = -1, maxd = 0, cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        if (dis[i] > maxd)
        {
            maxd = dis[i], p = i, cnt = 1;
        }
        else if (dis[i] == maxd)
        {
            cnt++;
        }
    }
    cout << p << " " << maxd << " " << cnt << endl;
    return 0;
}
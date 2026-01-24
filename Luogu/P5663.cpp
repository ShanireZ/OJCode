#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> to[100005];
queue<pair<int, int>> q;
int n, m, t, dis[100005][2]; // 0偶1奇
int main()
{
    cin >> n >> m >> t;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v), to[v].push_back(u);
    }
    memset(dis, 0x3f, sizeof(dis));
    q.push({1, 0});
    while (q.size())
    {
        int now = q.front().first, step = q.front().second;
        q.pop();
        for (int nxt : to[now])
        {
            if (dis[nxt][(step + 1) % 2] > step + 1)
            {
                dis[nxt][(step + 1) % 2] = step + 1, q.push({nxt, step + 1});
            }
        }
    }
    for (int i = 1; i <= t; i++)
    {
        int a, l;
        cin >> a >> l;
        cout << (dis[a][l % 2] <= l ? "Yes" : "No") << endl;
    }
    return 0;
}
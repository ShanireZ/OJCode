#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
queue<int> q;
vector<int> g[105];
int vis[105];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        fill(vis + 1, vis + 1 + n, 0), q.push(i);
        int cnt = 0;
        while (q.size())
        {
            int now = q.front();
            q.pop(), vis[now] = 1, cnt++;
            for (int j = 0; j < (int)g[now].size(); j++)
            {
                if (vis[g[now][j]] == 0)
                {
                    q.push(g[now][j]);
                }
            }
        }
        if (cnt == n)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
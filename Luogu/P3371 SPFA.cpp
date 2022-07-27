#include <iostream>
#include <queue>
using namespace std;
#define MX 100005
queue<int> q;
int n, m, s;
int last[MX], to[MX * 5], pre[MX * 5], in[MX], dis[MX], w[MX * 5];
int main()
{
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v >> w[i];
        pre[i] = last[u], to[i] = v;
        last[u] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = 2147483647;
    }
    dis[s] = 0, in[s] = 1;
    q.push(s);
    while (q.size())
    {
        int f = q.front();
        q.pop(), in[f] = 0;
        for (int i = last[f]; i; i = pre[i])
        {
            int t = to[i];
            if (dis[f] + w[i] >= dis[t])
            {
                continue;
            }
            dis[t] = dis[f] + w[i];
            if (in[t] == 0)
            {
                in[t] = 1, q.push(t);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
    return 0;
}
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
struct Path
{
    int tar, dis, times;
    bool operator<(const Path oth) const
    {
        return dis > oth.dis;
    }
};
priority_queue<Path> q;
int read(), dis[10005][5], ok[10005][5], last[10005], to[200005], d[200005], pre[200005], tag[200005];
void addEdge(int u, int v, int w, int x, int id)
{
    pre[id] = last[u], to[id] = v, d[id] = w, tag[id] = x;
    last[u] = id;
}
int main()
{
    int n = read(), m = read(), pos = 0;
    for (int i = 1; i <= m; i++)
    {
        int a = read(), b = read(), c = read(), d = read();
        addEdge(a, b, c, d, ++pos), addEdge(b, a, c, d, ++pos);
    }
    memset(dis, 0x3f, sizeof(dis));
    q.push(Path{1, 0, 0}), dis[1][0] = 0;
    while (q.size())
    {
        int now = q.top().tar, t = q.top().times;
        q.pop();
        if (ok[now][t])
        {
            continue;
        }
        ok[now][t] = 1;
        for (int i = last[now]; i; i = pre[i])
        {
            int nxt = to[i], dntn = d[i];
            if (tag[i] && t <= 1 && dis[nxt][t + 1] > dntn + dis[now][t])
            {
                dis[nxt][t + 1] = dntn + dis[now][t];
                q.push(Path{nxt, dis[nxt][t + 1], t + 1});
            }
            else if (tag[i] == 0 && dis[nxt][t] > dntn + dis[now][t])
            {
                dis[nxt][t] = dntn + dis[now][t];
                q.push(Path{nxt, dis[nxt][t], t});
            }
        }
    }
    cout << max(dis[n][0] - dis[n][1], dis[n][0] - dis[n][2]) << "\n";
    return 0;
}
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}
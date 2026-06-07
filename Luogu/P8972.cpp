#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
#define MX 200005
struct Edge
{
    int to, d2, d5, zero;
};
vector<Edge> es[MX];
queue<int> que;
string sw;
int n, q, dep[MX], anc[MX][20], z[MX], vis[MX];
long long a[MX], s2[MX], s5[MX];
long long parseW(string s)
{
    long long ip = 0, fp = 0, scale = 1000, dot = -1;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == '.')
        {
            dot = i;
            break;
        }
    }
    if (dot == -1)
    {
        for (char c : s)
        {
            ip = ip * 10 + (c - '0');
        }
        return ip * 10000;
    }
    for (int i = 0; i < dot; i++)
    {
        ip = ip * 10 + (s[i] - '0');
    }
    for (int i = dot + 1; i < (int)s.size() && scale > 0; i++)
    {
        fp += (s[i] - '0') * scale, scale /= 10;
    }
    return ip * 10000 + fp;
}
int val(long long x, int p)
{
    int c = 0;
    while (x % p == 0)
    {
        x /= p, c++;
    }
    return c;
}
void bfs()
{
    que.push(1), vis[1] = 1;
    while (que.size())
    {
        int now = que.front();
        que.pop();
        for (Edge e : es[now])
        {
            int nxt = e.to;
            if (vis[nxt])
            {
                continue;
            }
            vis[nxt] = 1;
            dep[nxt] = dep[now] + 1;
            anc[nxt][0] = now;
            s2[nxt] = s2[now] + e.d2;
            s5[nxt] = s5[now] + e.d5;
            z[nxt] = z[now] + e.zero;
            que.push(nxt);
        }
    }
    for (int j = 1; j <= 18; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            anc[i][j] = anc[anc[i][j - 1]][j - 1];
        }
    }
}
int lca(int x, int y)
{
    if (dep[x] < dep[y])
    {
        swap(x, y);
    }
    for (int i = 18; i >= 0; i--)
    {
        if (dep[anc[x][i]] >= dep[y])
        {
            x = anc[x][i];
        }
    }
    if (x == y)
    {
        return x;
    }
    for (int i = 18; i >= 0; i--)
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v >> sw;
        long long p = parseW(sw);
        if (p == 0)
        {
            es[u].push_back(Edge{v, 0, 0, 1});
            es[v].push_back(Edge{u, 0, 0, 1});
        }
        else
        {
            int d2 = val(p, 2) - 4, d5 = val(p, 5) - 4;
            es[u].push_back(Edge{v, d2, d5, 0});
            es[v].push_back(Edge{u, d2, d5, 0});
        }
    }
    bfs();
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        int l = lca(x, y);
        if (a[x] == 0 || z[x] + z[y] - 2 * z[l] > 0)
        {
            cout << "Yes" << endl;
            continue;
        }
        long long tot2 = s2[x] + s2[y] - 2 * s2[l];
        long long tot5 = s5[x] + s5[y] - 2 * s5[l];
        long long v2 = val(a[x], 2), v5 = val(a[x], 5);
        if (v2 + tot2 >= 0 && v5 + tot5 >= 0)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
// TAG: LCA 倍增 树上前缀和 数论 质因数分解
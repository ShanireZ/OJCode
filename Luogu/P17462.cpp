#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Edge
{
    int to, l, t;
};
vector<Edge> es[505];
struct Node
{
    int to, v;
    bool operator<(const Node &other) const
    {
        return v < other.v;
    }
};
priority_queue<Node> p;
int n, m, q, ans[505][505];
int main()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++)
    {
        int u, v, l, t;
        cin >> u >> v >> l >> t;
        es[v].push_back(Edge{u, l, t});
    }
    memset(ans, -1, sizeof(ans));
    for (int i = 1; i <= n; i++)
    {
        p.push(Node{i, 1000000});
        while (p.size())
        {
            int now = p.top().to, v = p.top().v;
            p.pop();
            if (ans[now][i] == -1)
            {
                ans[now][i] = v;
                for (Edge e : es[now])
                {
                    int nxt = e.to;
                    int nv = min(e.l, ans[now][i] - e.t);
                    if (ans[nxt][i] == -1)
                    {
                        p.push(Node{nxt, nv});
                    }
                }
            }
        }
    }
    while (q--)
    {
        int u, v, s;
        cin >> u >> v >> s;
        cout << (ans[u][v] >= s ? "Yes" : "No") << "\n";
    }
    cout << endl;
    return 0;
}
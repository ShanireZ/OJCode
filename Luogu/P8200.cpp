#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Edge
{
    int v;
    unsigned long long w;
};
vector<Edge> es[500005];
unsigned long long dis[500005];
void dfs(int now, int from, unsigned long long x)
{
    dis[now] = x;
    for (auto e : es[now])
    {
        if (e.v == from)
        {
            continue;
        }
        dfs(e.v, now, x ^ e.w);
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        unsigned long long l;
        cin >> x >> y >> l;
        es[x].push_back(Edge{y, l}), es[y].push_back(Edge{x, l});
    }
    dfs(1, 0, 0);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        unsigned long long k;
        cin >> a >> b >> k;
        if ((dis[a] ^ dis[b]) == k)
        {
            cout << "Yes" << '\n';
        }
        else
        {
            cout << "No" << '\n';
        }
    }
    return 0;
}
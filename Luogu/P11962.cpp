#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> g[200005];
int n, c0, c1, h[200005];
void dfs(int now, int from)
{
    h[now] % 2 ? c1++ : c0++;
    for (int nxt : g[now])
    {
        if (nxt == from)
        {
            continue;
        }
        h[nxt] = h[now] + 1, dfs(nxt, now);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b), g[b].emplace_back(a);
    }
    h[1] = 1, dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        cout << (h[i] % 2 ? c1 : c0) << ' ';
    }
    return 0;
}
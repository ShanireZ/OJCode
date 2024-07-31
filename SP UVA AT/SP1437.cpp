#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int d1[10005], d2[10005], ans;
vector<int> to[10005];
void dfs(int now, int from)
{
    for (int nxt : to[now])
    {
        if (nxt == from)
        {
            continue;
        }
        dfs(nxt, now);
        if (d1[nxt] + 1 > d1[now])
        {
            d2[now] = d1[now], d1[now] = d1[nxt] + 1;
        }
        else if (d1[nxt] + 1 > d2[now])
        {
            d2[now] = d1[nxt] + 1;
        }
    }
    ans = max(ans, d1[now] + d2[now]);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].emplace_back(v), to[v].emplace_back(u);
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}
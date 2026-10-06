#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> to[20005];
int n, ans = 20000, sz[20005];
void dfs(int now, int from)
{
    sz[now] = 1;
    for (int nxt : to[now])
    {
        if (nxt == from)
        {
            continue;
        }
        dfs(nxt, now);
        sz[now] += sz[nxt];
    }
    ans = min(ans, abs(n - 2 * sz[now]));
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}
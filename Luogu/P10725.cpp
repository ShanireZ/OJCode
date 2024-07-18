#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
vector<int> to[100005];
int col[100005], h[100005][2], ans;
void dfs(int now, int from)
{
    h[now][col[now]] = 0;
    for (int nxt : to[now])
    {
        if (nxt == from)
        {
            continue;
        }
        dfs(nxt, now);
        ans = max(ans, max(h[now][0] + h[nxt][1], h[now][1] + h[nxt][0]) + 1); // 以now为lca不同子树拼接
        h[now][0] = max(h[now][0], h[nxt][0] + 1);
        h[now][1] = max(h[now][1], h[nxt][1] + 1);
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> col[i];
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v), to[v].push_back(u);
    }
    memset(h, -0x3f, sizeof(h));
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}
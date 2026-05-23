#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> to[100005];
int n, ans, zd[100005], cd[100005], vis[100005];
void dfs(int now)
{
    vis[now] = 1;
    for (int nxt : to[now])
    {
        if (vis[nxt])
        {
            continue;
        }
        dfs(nxt);
        if (zd[nxt] + 1 > zd[now])
        {
            cd[now] = zd[now];
            zd[now] = zd[nxt] + 1;
        }
        else if (zd[nxt] + 1 > cd[now])
        {
            cd[now] = zd[nxt] + 1;
        }
    }
    ans = max(ans, zd[now] + cd[now]);
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v), to[v].push_back(u);
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}
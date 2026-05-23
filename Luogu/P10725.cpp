#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> to[100005];
int n, ans, res, wtpos, bkpos, dis[100005], c[100005];
void dfs(int now, int from)
{
    for (int nxt : to[now])
    {
        if (nxt == from)
        {
            continue;
        }
        dis[nxt] = dis[now] + 1;
        if (c[nxt] == 1 && dis[nxt] > dis[bkpos])
        {
            bkpos = nxt;
        }
        else if (c[nxt] == 0 && dis[nxt] > dis[wtpos])
        {
            wtpos = nxt;
        }
        dfs(nxt, now);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    dfs(1, 0);
    int bk = bkpos, wt = wtpos;
    bkpos = wtpos = 0, dis[bk] = 0, dfs(bk, 0);
    ans = max(ans, dis[wtpos]);
    bkpos = wtpos = 0, dis[wt] = 0, dfs(wt, 0);
    ans = max(ans, dis[bkpos]);
    cout << ans << endl;
    return 0;
}
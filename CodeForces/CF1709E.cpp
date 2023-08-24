#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
#define MX 200005
int a[MX], n, ans;
set<int> s[MX];
vector<int> to[MX];
void dfs(int now, int fa, int xr)
{
    s[now].insert(xr ^ a[now]);
    int flag = 0;
    for (int nxt : to[now])
    {
        if (nxt == fa)
        {
            continue;
        }
        dfs(nxt, now, xr ^ a[now]);
        if (flag == 1)
        {
            continue;
        }
        if (s[now].size() < s[nxt].size())
        {
            swap(s[nxt], s[now]);
        }
        for (int x : s[nxt])
        {
            if (s[now].find(x ^ a[now]) != s[now].end())
            {
                flag = 1;
                break;
            }
        }
        for (int x : s[nxt])
        {
            s[now].insert(x);
        }
    }
    if (flag)
    {
        set<int>().swap(s[now]);
        ans++;
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v), to[v].push_back(u);
    }
    dfs(1, 0, 0);
    cout << ans << endl;
    return 0;
}
// TAG: 树上启发式合并 DSU on tree xor路径
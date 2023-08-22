#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
set<int> ans;
vector<int> to[10005];
int sz[10005], n;
void dfs(int now, int from)
{
    int ok = 1;
    for (int nxt : to[now])
    {
        if (nxt != from)
        {
            dfs(nxt, now);
            sz[now] += sz[nxt];
            if (sz[nxt] > n / 2)
            {
                ok = 0;
            }
        }
    }
    sz[now] += 1;
    if (n - sz[now] > n / 2)
    {
        ok = 0;
    }
    if (ok)
    {
        ans.insert(now);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        to[a].push_back(b), to[b].push_back(a);
    }
    dfs(1, 0);
    if (ans.size())
    {
        for (int x : ans)
        {
            cout << x << "\n";
        }
    }
    else
    {
        cout << "NONE\n";
    }
    return 0;
}
// TAG: 子树 树上DP 搜索 DFS
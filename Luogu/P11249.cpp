#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int a[100005], rec[100005], T, pos, n, ans;
vector<int> to[100005];
void dfs(int now, int from)
{
    if (a[now])
    {
        rec[pos] = 1;
    }
    for (int i = 0; i < (int)to[now].size(); i++)
    {
        int nxt = to[now][i];
        if (nxt == from)
        {
            continue;
        }
        dfs(nxt, now);
    }
    if (a[now])
    {
        pos++;
    }
}
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            to[i].clear(), rec[i] = 0;
            cin >> a[i];
        }
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            to[u].emplace_back(v), to[v].emplace_back(u);
        }
        pos = 1, ans = 0, dfs(1, 0);
        for (int i = 1; i <= pos; i++)
        {
            ans += rec[i];
        }
        cout << (ans <= 2 ? "Yes" : "No") << endl;
    }
    return 0;
}
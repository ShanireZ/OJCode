#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> to[100005];
int ans[100005];
void dfs(int now, int st)
{
    if (ans[now])
    {
        return;
    }
    ans[now] = st;
    for (int nxt : to[now])
    {
        dfs(nxt, st);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        to[v].push_back(u);
    }
    for (int i = n; i > 0; i--)
    {
        dfs(i, i);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
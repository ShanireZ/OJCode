#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> to[100005];
int col[100005];
void dfs(int now, int fa)
{
    for (int nxt : to[now])
    {
        if (nxt != fa)
        {
            continue;
        }
        dfs(nxt, now);
        if (col[nxt] == 1)
        {
            col[now] = 1;
        }
    }
}
int main()
{
    int n, st = 0, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> col[i];
        if (col[i] == 1)
        {
            st = i, cnt++;
        }
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v), to[v].push_back(u);
    }
    dfs(st, 0);
    for (int i = 1; i <= n; i++)
    {
        cnt -= col[i];
    }
    cout << -cnt << endl;
    return 0;
}
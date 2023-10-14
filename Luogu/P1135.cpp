#include <algorithm>
#include <iostream>
using namespace std;
int k[205], vis[205], ans[205], n, a, b;
void dfs(int now, int step)
{
    ans[now] = min(ans[now], step);
    if (now + k[now] <= n && vis[now + k[now]] == 0 && step + 1 < ans[now + k[now]])
    {
        vis[now + k[now]] = 1;
        dfs(now + k[now], step + 1);
        vis[now + k[now]] = 0;
    }
    if (now - k[now] >= 1 && vis[now - k[now]] == 0 && step + 1 < ans[now - k[now]])
    {
        vis[now - k[now]] = 1;
        dfs(now - k[now], step + 1);
        vis[now - k[now]] = 0;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
        ans[i] = 1e9;
    }
    dfs(a, 0);
    if (ans[b] == 1e9)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans[b] << endl;
    }
    return 0;
}
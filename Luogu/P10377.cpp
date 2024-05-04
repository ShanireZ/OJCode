#include <algorithm>
#include <iostream>
using namespace std;
int a[15], b[15], pos[15], vis[15], ans = 1e9, n;
void dfs(int now)
{
    if (now > n)
    {
        int res = n;
        for (int i = 2; i <= n; i++)
        {
            res = res + max(b[pos[i - 1]], a[pos[i]]);
        }
        ans = min(ans, res);
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 1)
        {
            continue;
        }
        vis[i] = 1, pos[now] = i;
        dfs(now + 1);
        vis[i] = 0;
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}
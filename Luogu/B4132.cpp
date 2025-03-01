#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
string s[55];
vector<int> to[55];
int n, ans, dis[55], vis[55];
void dfs(int now, int cnt)
{
    vis[now] = 1;
    for (int nxt : to[now])
    {
        if (vis[nxt])
        {
            continue;
        }
        dfs(nxt, cnt + 1);
    }
    vis[now] = 0, dis[now] = max(dis[now], cnt);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                continue;
            }
            if (s[i][1] == s[j][0])
            {
                to[i].emplace_back(j);
            }
        }
        dis[i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        dfs(i, 1);
    }
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dis[i]);
    }
    cout << ans << endl;
    return 0;
}
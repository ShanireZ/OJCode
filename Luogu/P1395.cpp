#include <iostream>
#include <vector>
using namespace std;
vector<int> to[50005];
int n, ans, root = 1, dp[50005], sz[50005], fa[50005];
void init(int now)
{
    sz[now] = 1;
    for (int i = 0; i < int(to[now].size()); i++)
    {
        int t = to[now][i];
        if (t == fa[now])
        {
            continue;
        }
        fa[t] = now;
        init(t);
        sz[now] += sz[t];
    }
    if (root != now)
    {
        dp[root] += sz[now];
    }
}
void dfs(int now)
{
    if (root != now)
    {
        dp[now] = dp[fa[now]] - sz[now] + (n - sz[now]);
        if (dp[now] < dp[ans] || (dp[now] == dp[ans] && now < ans))
        {
            ans = now;
        }
    }
    for (int i = 0; i < int(to[now].size()); i++)
    {
        int t = to[now][i];
        if (t == fa[now])
        {
            continue;
        }
        dfs(t);
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
    init(root);
    ans = root;
    dfs(root);
    cout << ans << " " << dp[ans] << endl;
    return 0;
}
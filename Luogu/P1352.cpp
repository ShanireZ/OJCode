#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int read();
// dp[i][0]表示i不参加 dp[i][1]表示i参加
int dp[6005][2];
struct Node
{
    vector<int> to;
    int fa, r;
};
Node ns[6005];
void dfs(int now)
{
    dp[now][1] = ns[now].r;
    for (int i = 0; i < ns[now].to.size(); i++)
    {
        int to = ns[now].to[i];
        if (to == ns[now].fa)
        {
            continue;
        }
        dfs(to);
        dp[now][1] += dp[to][0];
        dp[now][0] += max(dp[to][0], dp[to][1]);
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].r;
    }
    for (int i = 1; i < n; i++)
    {
        int l, k;
        cin >> l >> k;
        ns[l].fa = k;
        ns[k].to.push_back(l);
    }
    int root;
    for (int i = 1; i <= n; i++)
    {
        if (ns[i].fa == 0)
        {
            root = i;
            break;
        }
    }
    dfs(root);
    cout << max(dp[root][0], dp[root][1]) << endl;
    return 0;
}
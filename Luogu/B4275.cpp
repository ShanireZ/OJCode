#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> chs[100005];
int n, root, v[100005], dp[100005][2];
void dfs(int now)
{
    dp[now][1] = v[now];
    for (int nxt : chs[now])
    {
        dfs(nxt);
        dp[now][0] += max(dp[nxt][0], dp[nxt][1]);
        dp[now][1] += dp[nxt][0];
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int f, s, c;
        cin >> f >> s >> c;
        chs[f].emplace_back(s), v[s] = c;
        if (f == 0)
        {
            root = s;
        }
    }
    dfs(root);
    cout << max(dp[root][1], dp[root][0]) << endl;
    return 0;
}
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, m, ind[100005], dp[100005];
vector<int> to[100005];
queue<int> q;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v), ind[v]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (ind[i] == 0)
        {
            dp[i] = 1, q.push(i);
        }
    }
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (int i = 0; i < int(to[now].size()); i++)
        {
            int nxt = to[now][i];
            if (--ind[nxt] == 0)
            {
                dp[nxt] = dp[now] + 1, q.push(nxt);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dp[i] << "\n";
    }
    return 0;
}
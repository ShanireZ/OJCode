#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> to[205];
long long pip[205][205], ok[205][205], pos[205], dp[205], n, m, s, t;
bool bfs()
{
    fill(dp, dp + 1 + n, 0);
    fill(pos, pos + 1 + n, 0);
    queue<int> q;
    q.push(s), dp[s] = 1;
    while (q.size())
    {
        int now = q.front();
        q.pop();
        if (now == t)
        {
            return true;
        }
        for (int nxt : to[now])
        {
            if (dp[nxt] || pip[now][nxt] == 0)
            {
                continue;
            }
            q.push(nxt), dp[nxt] = dp[now] + 1;
        }
    }
    return false;
}
long long dfs(int now, long long flow)
{
    if (now == t)
    {
        return flow;
    }
    long long sum = 0;
    for (int i = pos[now]; i < (int)to[now].size(); i++)
    {
        int nxt = to[now][i];
        if (dp[now] != dp[nxt] - 1 || pip[now][nxt] == 0)
        {
            continue;
        }
        long long ex = dfs(nxt, min(flow, pip[now][nxt]));
        pip[now][nxt] -= ex, pip[nxt][now] += ex;
        sum += ex, flow -= ex, pos[now]++;
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (ok[u][v] == 0)
        {
            ok[u][v] = 1, to[u].push_back(v);
            ok[v][u] = 1, to[v].push_back(u);
        }
        pip[u][v] += w;
    }
    long long ans = 0;
    while (bfs())
    {
        ans += dfs(s, 1e15);
    }
    cout << ans << endl;
    return 0;
}
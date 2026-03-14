#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> es[50005];
struct Path
{
    long long ed, len;
    bool operator<(const Path &oth) const
    {
        return len > oth.len;
    }
};
priority_queue<Path> q;
long long n, m, ans = 1e18, s[5], c[5], dis[5][50005];
int main()
{
    cin >> c[1] >> c[2] >> c[3] >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        es[u].push_back(v);
        es[v].push_back(u);
    }
    s[1] = 1, s[2] = 2, s[3] = n;
    memset(dis, 0x3f, sizeof(dis));
    for (int k = 1; k <= 3; k++)
    {
        q.push(Path{s[k], 0});
        while (q.size())
        {
            int now = q.top().ed, len = q.top().len;
            q.pop();
            if (dis[k][now] > len)
            {
                dis[k][now] = len;
                for (int nxt : es[now])
                {
                    if (dis[k][nxt] > len + c[k])
                    {
                        q.push(Path{nxt, len + c[k]});
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        long long sum = dis[1][i] + dis[2][i] + dis[3][i];
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
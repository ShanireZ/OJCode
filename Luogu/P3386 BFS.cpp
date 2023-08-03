#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MX 505
vector<int> to[MX];
queue<int> q;
int vis[MX], l[MX], r[MX], wait[MX]; // vis右侧点标记
bool bfs(int st, int t)
{
    queue<int> ept;
    swap(q, ept), memset(wait, 0, sizeof(wait)), q.push(st);
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (int nxt : to[now])
        {
            if (vis[nxt] != t)
            {
                vis[nxt] = t, wait[nxt] = now;
                if (r[nxt] == 0)
                {
                    while (nxt)
                    {
                        int x = wait[nxt]; // 当前待给右侧点安排的左侧点
                        r[nxt] = x;
                        swap(l[x], nxt); // 后续再继续安排左侧点之前的匹配对象
                    }
                    return true;
                }
                else
                {
                    q.push(r[nxt]); // 后续再尝试安排冲突的左侧点
                }
            }
        }
    }
    return false;
}
int main()
{
    int n, m, e, ans = 0;
    cin >> n >> m >> e;
    for (int i = 1; i <= e; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        ans += bfs(i, i);
    }
    cout << ans << "\n";
    return 0;
}
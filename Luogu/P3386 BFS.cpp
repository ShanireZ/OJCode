#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MX 505
vector<int> to[MX];
queue<int> q;
int vis[MX], l[MX], r[MX], wait[MX]; // vis右側點標記
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
                        int x = wait[nxt]; // 當前待給右側點安排的左側點
                        r[nxt] = x;
                        swap(l[x], nxt); // 後續再繼續安排左側點之前的匹配物件
                    }
                    return true;
                }
                else
                {
                    q.push(r[nxt]); // 後續再嘗試安排衝突的左側點
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
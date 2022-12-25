#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;
struct Path
{
    int tar;
    long long dis;
    bool operator<(const Path oth) const
    {
        return dis > oth.dis;
    }
};
priority_queue<Path> q;
unordered_map<string, int> mp;
int last[1005], pre[1005], to[1005], ok[1005][1005];
long long dis[1005][1005], d[1005];
int main()
{
    ios::sync_with_stdio(false);
    int n, m, spos = 0, epos = 0;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        string a, b;
        long long w;
        cin >> a >> b >> w;
        if (mp[a] == 0)
        {
            mp[a] = ++spos;
        }
        if (mp[b] == 0)
        {
            mp[b] = ++spos;
        }
        pre[++epos] = last[mp[a]];
        to[epos] = mp[b], d[epos] = w, last[mp[a]] = epos;
    }
    memset(dis, 0x3f, sizeof(dis));
    for (int st = 1; st <= n; st++)
    {
        dis[st][st] = 0, q.push(Path{st, 0});
        while (q.size())
        {
            int now = q.top().tar;
            q.pop();
            if (ok[st][now])
            {
                continue;
            }
            ok[st][now] = 1;
            for (int i = last[now]; i; i = pre[i])
            {
                int nxt = to[i], w = d[i];
                if (dis[st][nxt] > dis[st][now] + w)
                {
                    dis[st][nxt] = dis[st][now] + w;
                    q.push(Path{nxt, dis[st][nxt]});
                }
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        string a, b;
        cin >> a >> b;
        if (dis[mp[a]][mp[b]] == 0x3f3f3f3f3f3f3f3f)
        {
            cout << "Roger\n";
        }
        else
        {
            cout << dis[mp[a]][mp[b]] << "\n";
        }
    }
    return 0;
}
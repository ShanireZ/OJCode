#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
struct Node
{
    int mid, t, pid;
};
Node sx[405];
struct Mac
{
    int l, r;
    bool operator<(const Mac &oth) const
    {
        return l < oth.l;
    }
};
set<Mac> mac[25];
int last[25], rd[25], a[25][25][2], n, m, tot;
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= m * n; i++)
    {
        cin >> sx[i].pid;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j][0];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j][1];
            tot += a[i][j][1];
        }
    }
    for (int i = 1; i <= m * n; i++)
    {
        int pid = sx[i].pid;
        int r = ++rd[pid];
        sx[i].mid = a[pid][r][0], sx[i].t = a[pid][r][1];
    }
    for (int i = 1; i <= m; i++)
    {
        mac[i].insert(Mac{0, tot + 5});
        mac[i].insert(Mac{tot + 5, tot + 10});
    }
    for (int i = 1; i <= m * n; i++)
    {
        int pid = sx[i].pid, mid = sx[i].mid;
        int st = last[pid], cost = sx[i].t;
        auto it = mac[mid].lower_bound(Mac{st, 0});
        if (it != mac[mid].begin())
        {
            it--;
            int l = it->l, r = it->r;
            if (st >= l && st <= r && r - st >= cost)
            {
                mac[mid].erase(it);
                mac[mid].insert(Mac{l, st});
                if (st + cost != r)
                {
                    mac[mid].insert(Mac{st + cost, r});
                }
                last[pid] = st + cost;
                continue;
            }
            it++;
        }
        while (it->r - it->l < cost)
        {
            it++;
        }
        int l = it->l, r = it->r;
        mac[mid].erase(it);
        if (l + cost != r)
        {
            mac[mid].insert(Mac{l + cost, r});
        }
        last[pid] = l + cost;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, last[i]);
    }
    cout << ans << endl;
    return 0;
}
// TAG: 大模拟 珂朵莉树
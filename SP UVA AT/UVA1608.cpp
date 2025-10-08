#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
struct Edge
{
    int x, down, up, opt;
};
Edge es[400005];
struct Node
{
    int lc, rc, t, v;
};
Node ns[800005];
map<int, int> mp;
int T, n, epos, npos, root, pre[200005], nxt[200005], a[200005];
bool cmp(Edge a, Edge b)
{
    return a.x < b.x;
}
void maketree(int &now, int l, int r)
{
    now = ++npos;
    ns[now] = Node{0, 0, 0, 0};
    if (l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    maketree(ns[now].lc, l, mid);
    maketree(ns[now].rc, mid + 1, r);
}
void edit(int now, int l, int r, int x, int y, int k)
{
    if (x <= l && y >= r)
    {
        ns[now].t += k;
        ns[now].v = (ns[now].t ? r - l + 1 : ns[ns[now].lc].v + ns[ns[now].rc].v);
        return;
    }
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        edit(ns[now].lc, l, mid, x, y, k);
    }
    if (y > mid)
    {
        edit(ns[now].rc, mid + 1, r, x, y, k);
    }
    ns[now].v = (ns[now].t ? r - l + 1 : ns[ns[now].lc].v + ns[ns[now].rc].v);
}
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        mp.clear(), root = npos = epos = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            pre[i] = mp[a[i]], nxt[i] = n + 1;
            mp[a[i]] = nxt[pre[i]] = i;
        }
        for (int i = 1; i <= n; i++)
        {
            int l = pre[i] + 1, r = nxt[i] - 1;
            es[++epos] = Edge{l, i, r + 1, 1};
            es[++epos] = Edge{i + 1, i, r + 1, -1};
        }
        sort(es + 1, es + epos + 1, cmp);
        maketree(root, 1, n);
        long long ans = 0;
        for (int i = 1, lst = 0; i <= epos; i++)
        {
            ans += 1ll * (es[i].x - lst) * ns[root].v;
            edit(root, 1, n, es[i].down, es[i].up - 1, es[i].opt);
            lst = es[i].x;
        }
        cout << (ans == 1ll * n * (n + 1) / 2 ? "non-boring" : "boring") << endl;
    }
    return 0;
}
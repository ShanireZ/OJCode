#include <iostream>
#include <string>
using namespace std;
struct Edge
{
    double s, p;
};
Edge es[100005];
struct Node
{
    int lc, rc, id;
};
Node ns[200005];
int cnt, root, n;
void init(int &now, int l, int r)
{
    now = ++cnt;
    if (l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    init(ns[now].lc, l, mid);
    init(ns[now].rc, mid + 1, r);
}
double count(int id, int k)
{
    return es[id].s + es[id].p * (k - 1);
}
void edit(int now, int l, int r, int nid)
{
    int id = ns[now].id;
    if (l == r)
    {
        if (count(id, l) < count(nid, l))
        {
            ns[now].id = nid;
        }
        return;
    }
    int mid = (l + r) / 2;
    if (es[id].p < es[nid].p)
    {
        if (count(id, mid) < count(nid, mid))
        {
            ns[now].id = nid;
            edit(ns[now].lc, l, mid, id);
        }
        else
        {
            edit(ns[now].rc, mid + 1, r, nid);
        }
    }
    else
    {
        if (count(id, mid) < count(nid, mid))
        {
            ns[now].id = nid;
            edit(ns[now].rc, mid + 1, r, id);
        }
        else
        {
            edit(ns[now].lc, l, mid, nid);
        }
    }
}
double query(int now, int l, int r, int pos)
{
    int id = ns[now].id;
    double ans = count(id, pos);
    if (l != r)
    {
        int mid = (l + r) / 2;
        if (pos <= mid)
        {
            ans = max(ans, query(ns[now].lc, l, mid, pos));
        }
        else
        {
            ans = max(ans, query(ns[now].rc, mid + 1, r, pos));
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    init(root, 1, 50000);
    cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        string op;
        cin >> op;
        if (op[0] == 'P')
        {
            cnt++;
            cin >> es[cnt].s >> es[cnt].p;
            edit(root, 1, 50000, cnt);
        }
        else
        {
            int x;
            cin >> x;
            cout << int(query(root, 1, 50000, x) / 100) << endl;
        }
    }
    return 0;
}
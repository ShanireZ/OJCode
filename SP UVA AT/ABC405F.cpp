#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int x, y, id; // id:0修改 其他查询id
};
Node ns[400005];
bool cmpy(Node a, Node b)
{
    return a.y == b.y ? a.id < b.id : a.y < b.y;
}
bool cmpx(Node a, Node b)
{
    return a.x == b.x ? a.id < b.id : a.x > b.x;
}
int n, m, q, ans[200005], tr[4000005];
void edit(int x, int v)
{
    while (x <= n)
    {
        tr[x] += v;
        x += (x & -x);
    }
}
int query(int x)
{
    int res = 0;
    while (x)
    {
        res += tr[x];
        x -= (x & -x);
    }
    return res;
}
int main()
{
    cin >> n >> m;
    n *= 2;
    for (int i = 1; i <= m; i++)
    {
        cin >> ns[i].x >> ns[i].y;
    }
    cin >> q;
    for (int i = m + 1; i <= m + q; i++)
    {
        cin >> ns[i].x >> ns[i].y;
        ns[i].id = i - m;
    }
    sort(ns + 1, ns + 1 + m + q, cmpx);
    for (int i = 1; i <= m + q; i++)
    {
        if (ns[i].id == 0)
        {
            edit(ns[i].x, 1), edit(ns[i].y + 1, -1);
        }
        else
        {
            ans[ns[i].id] += query(ns[i].y);
        }
    }
    sort(ns + 1, ns + 1 + m + q, cmpy);
    fill(tr + 1, tr + 1 + n, 0);
    for (int i = 1; i <= m + q; i++)
    {
        if (ns[i].id == 0)
        {
            edit(ns[i].x, 1), edit(ns[i].y + 1, -1);
        }
        else
        {
            ans[ns[i].id] += query(ns[i].x);
        }
    }
    for (int i = 1; i <= q; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}
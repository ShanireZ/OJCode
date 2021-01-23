#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
struct Node
{
    int v, l, r, size, idx, fa;
};
Node ns[80005];
int root, pos, id[80005], a, b, c, d;
int newnode(int x)
{
    ns[++pos].v = x;
    ns[pos].size = 1;
    ns[pos].idx = rand();
    return pos;
}
void update(int now)
{
    ns[now].size = ns[ns[now].l].size + ns[ns[now].r].size + 1;
    ns[ns[now].r].fa = ns[ns[now].l].fa = now;
}
void split(int now, int sz, int &x, int &y)
{
    if (now == 0)
    {
        x = y = 0;
        return;
    }
    if (ns[ns[now].l].size + 1 <= sz)
    {
        x = now;
        split(ns[now].r, sz - ns[ns[now].l].size - 1, ns[x].r, y);
    }
    else
    {
        y = now;
        split(ns[now].l, sz, x, ns[y].l);
    }
    update(now);
}
int merge(int x, int y)
{
    if (x == 0 || y == 0)
    {
        return x + y;
    }
    if (ns[x].idx >= ns[y].idx)
    {
        ns[x].r = merge(ns[x].r, y);
        update(x);
        return x;
    }
    else
    {
        ns[y].l = merge(x, ns[y].l);
        update(y);
        return y;
    }
}
int getsize(int x)
{
    int tot = ns[ns[x].l].size + 1;
    while (ns[x].fa)
    {
        if (x == ns[ns[x].fa].r)
        {
            tot += ns[ns[ns[x].fa].l].size + 1;
        }
        x = ns[x].fa;
    }
    return tot;
}
int main()
{
    srand(23333);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        root = merge(root, newnode(x));
        id[x] = pos;
    }
    for (int i = 1; i <= m; i++)
    {
        string opt;
        int s, t;
        cin >> opt >> s;
        if (opt == "Top") //把编号为s的书放在最上面
        {
            int sz = getsize(id[s]);
            split(root, sz - 1, a, b);
            split(b, 1, b, c);
            root = merge(merge(b, a), c);
        }
        else if (opt == "Bottom") //把编号为s的书放在最下面
        {
            int sz = getsize(id[s]);
            split(root, sz - 1, a, b);
            split(b, 1, b, c);
            root = merge(merge(a, c), b);
        }
        else if (opt == "Insert") //把编号为s的书放到x+t下面
        {
            cin >> t;
            if (t != 0)
            {
                int sz = getsize(id[s]);
                split(root, sz - 1, a, b);
                split(b, 1, b, c);
                if (t == -1)
                {
                    split(a, sz - 2, a, d);
                    root = merge(merge(merge(a, b), d), c);
                }
                else if (t == 1)
                {
                    split(c, 1, c, d);
                    root = merge(merge(merge(a, c), b), d);
                }
            }
        }
        else if (opt == "Ask") //询问编号为s的书上面有几本书
        {
            int sz = getsize(id[s]);
            cout << sz - 1 << endl;
        }
        else if (opt == "Query") //询问从上面起第s本书的编号
        {
            split(root, s - 1, a, b);
            split(b, 1, b, c);
            cout << ns[b].v << endl;
            root = merge(merge(a, b), c);
        }
    }
    return 0;
}
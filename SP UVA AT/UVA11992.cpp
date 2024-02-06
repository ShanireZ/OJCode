#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
int r, c, m, opt, xa, ya, xb, yb, k;
struct Node
{
    int l, r;
    mutable int v;
    bool operator<(const Node &oth) const
    {
        return l < oth.l;
    }
};
set<Node> s[23];
struct Ans
{
    int tot, maxv, minv;
};
set<Node>::iterator split(int x, int y)
{
    set<Node>::iterator it = s[x].lower_bound(Node{y, 0, 0});
    if (it->l == y)
    {
        return it;
    }
    it--;
    int l = it->l, r = it->r, v = it->v;
    s[x].erase(it);
    s[x].insert(Node{l, y - 1, v});
    return s[x].insert(Node{y, r, v}).first;
}
void add()
{
    for (int i = xa; i <= xb; i++)
    {
        set<Node>::iterator itr = split(i, yb + 1), itl = split(i, ya);
        for (set<Node>::iterator it = itl; it != itr; it++)
        {
            it->v += k;
        }
    }
}
void edit()
{
    for (int i = xa; i <= xb; i++)
    {
        set<Node>::iterator itr = split(i, yb + 1), itl = split(i, ya);
        s[i].erase(itl, itr);
        s[i].insert(Node{ya, yb, k});
    }
}
Ans query()
{
    Ans ans = Ans{0, 0, 0x3f3f3f3f};
    for (int i = xa; i <= xb; i++)
    {
        set<Node>::iterator itr = split(i, yb + 1), itl = split(i, ya);
        for (set<Node>::iterator it = itl; it != itr; it++)
        {
            ans.tot += (it->r - it->l + 1) * it->v;
            ans.maxv = max(ans.maxv, it->v);
            ans.minv = min(ans.minv, it->v);
        }
    }
    return ans;
}
int main()
{
    while (cin >> r >> c >> m)
    {
        for (int i = 1; i <= r; i++)
        {
            s[i].clear();
            s[i].insert(Node{1, c, 0});
            s[i].insert(Node{c + 1, c + 3, 0});
        }
        for (int i = 1; i <= m; i++)
        {
            cin >> opt >> xa >> ya >> xb >> yb;
            if (opt == 1) // add
            {
                cin >> k;
                add();
            }
            else if (opt == 2) // edit
            {
                cin >> k;
                edit();
            }
            else // query
            {
                Ans ans = query();
                cout << ans.tot << " " << ans.minv << " " << ans.maxv << endl;
            }
        }
    }
    return 0;
}
// TAG: 珂朵莉树 ODT 二维线段树
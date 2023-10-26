#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define MX 20005
struct Node
{
    int l, r, op;
};
Node ns[MX];
int g[MX], all[MX], pos;
int dfn(int x)
{
    return g[x] == x ? x : g[x] = dfn(g[x]);
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        string str;
        int a, b;
        cin >> a >> b >> str;
        ns[i] = Node{a - 1, b, (str == "odd" ? 1 : 0)};
        all[++pos] = a - 1, all[++pos] = b;
    }
    sort(all + 1, all + 1 + pos);
    pos = unique(all + 1, all + 1 + pos) - all - 1;
    for (int i = 1; i <= pos * 2; i++)
    {
        g[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int a = lower_bound(all + 1, all + 1 + pos, ns[i].l) - all;
        int b = lower_bound(all + 1, all + 1 + pos, ns[i].r) - all;
        int ga0 = dfn(a), ga1 = dfn(a + pos), gb0 = dfn(b), gb1 = dfn(b + pos);
        if (ns[i].op == 0)
        {
            if (ga0 == gb1)
            {
                cout << i - 1 << endl;
                return 0;
            }
            g[ga0] = gb0, g[ga1] = gb1;
        }
        else
        {
            if (ga0 == gb0)
            {
                cout << i - 1 << endl;
                return 0;
            }
            g[ga0] = gb1, g[ga1] = gb0;
        }
    }
    cout << m << endl;
    return 0;
}
// TAG: 种类并查集 前缀
#include <algorithm>
#include <iostream>
using namespace std;
struct OPT
{
    int op, l, r, c, t;
};
OPT opts[2000005];
long long ch, cl, cnt[500005], gh[2000005], gl[2000005];
int dfn(int x, int op)
{
    if (op == 1 && x != gh[x])
    {
        gh[x] = dfn(gh[x], op);
    }
    else if (op == 2 && x != gl[x])
    {
        gl[x] = dfn(gl[x], op);
    }
    return (op == 1 ? gh[x] : gl[x]);
}
void make(int x)
{
    int now = dfn(opts[x].l, opts[x].op);
    while (now <= opts[x].r)
    {
        if (opts[x].op == 1)
        {
            cnt[opts[x].c] += cl, ch--;
            now = gh[now] = dfn(now + 1, opts[x].op);
        }
        else
        {
            cnt[opts[x].c] += ch, cl--;
            now = gl[now] = dfn(now + 1, opts[x].op);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> opts[i].op >> opts[i].l >> opts[i].r >> opts[i].c >> opts[i].t;
    }
    int maxp = max(n, m) + 1;
    for (int i = 1; i <= maxp; i++)
    {
        gh[i] = i, gl[i] = i;
    }
    ch = n, cl = m;
    for (int i = q; i >= 1; i--)
    {
        if (opts[i].t == 1)
        {
            make(i);
        }
    }
    for (int i = 1; i <= q; i++)
    {
        if (opts[i].t == 0)
        {
            make(i);
        }
    }
    for (int i = 1; i <= k; i++)
    {
        cout << cnt[i] << " ";
    }
    cout << endl;
    return 0;
}
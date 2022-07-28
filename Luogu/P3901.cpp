#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
#define MX 100005
int n, m, sz, cnt, st = 1, ed = 0;
int a[MX], bl[MX], ans[MX], t[MX];
struct Quest
{
    int id, l, r;
    bool operator<(const Quest oth) const
    {
        if (bl[l] == bl[oth.l])
        {
            return bl[r] < bl[oth.r];
        }
        return bl[l] < bl[oth.l];
    }
};
Quest q[MX];
void sub(int x)
{
    t[a[x]]--;
    if (t[a[x]] == 1)
    {
        cnt--;
    }
}
void add(int x)
{
    t[a[x]]++;
    if (t[a[x]] == 2)
    {
        cnt++;
    }
}
int main()
{
    cin >> n >> m;
    sz = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        bl[i] = i / sz + 1;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    sort(q + 1, q + 1 + m);
    for (int i = 1; i <= m; i++)
    {
        while (q[i].l > st)
        {
            sub(st++);
        }
        while (q[i].l < st)
        {
            add(--st);
        }
        while (q[i].r > ed)
        {
            add(++ed);
        }
        while (q[i].r < ed)
        {
            sub(ed--);
        }
        ans[q[i].id] = cnt;
    }
    for (int i = 1; i <= m; i++)
    {
        if (ans[i])
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
    return 0;
}
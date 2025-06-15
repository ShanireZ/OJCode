#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int l, r;
    bool operator<(const Node &oth) const
    {
        return l < oth.l;
    }
};
Node ns[25005];
int n, t, now, nxt = -1, cnt;
int main()
{
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].l >> ns[i].r;
    }
    sort(ns + 1, ns + n + 1);
    for (int i = 1; i <= n; i++)
    {
        while (ns[i].l > ns[now].r + 1)
        {
            if (nxt == -1)
            {
                cout << -1 << endl;
                return 0;
            }
            cnt++, now = nxt, nxt = -1;
        }
        if (ns[i].l <= ns[now].r + 1)
        {
            if (nxt == -1 || ns[i].r > ns[nxt].r)
            {
                nxt = i;
            }
        }
    }
    if (ns[now].r >= t)
    {
        cout << cnt << endl;
    }
    else if (nxt != -1 && ns[nxt].r >= t)
    {
        cout << cnt + 1 << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}
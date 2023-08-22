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
Node ns[30005];
int main()
{
    int n, t;
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].l >> ns[i].r;
    }
    sort(ns + 1, ns + n + 1);
    int now = 1, cnt = 0;
    for (int i = 1; i <= n && now <= t;)
    {
        int maxr = now;
        while (i <= n && ns[i].l <= now)
        {
            maxr = max(maxr, ns[i].r + 1);
            i++;
        }
        if (now == maxr)
        {
            cnt = -1;
            break;
        }
        now = maxr, cnt++;
    }
    if (now <= t)
    {
        cnt = -1;
    }
    cout << cnt << "\n";
    return 0;
}
// TAG: 贪心
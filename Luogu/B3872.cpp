#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
struct Node
{
    int t, r;
    bool operator<(const Node &oth) const
    {
        if (r == oth.r)
        {
            return t < oth.t;
        }
        return r > oth.r;
    }
};
Node ns[505];
set<int> s;
int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        s.insert(i);
        cin >> ns[i].t;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].r;
    }
    sort(ns + 1, ns + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        auto it = s.upper_bound(ns[i].t);
        if (it == s.begin()) // 没有更早的时间可以做这个游戏
        {
            continue;
        }
        ans += ns[i].r, s.erase(--it);
    }
    cout << ans << endl;
    return 0;
}
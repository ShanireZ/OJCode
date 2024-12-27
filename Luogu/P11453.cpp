#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
struct Node
{
    int l, r, t;
    bool operator<(const Node &oth) const
    {
        return r < oth.r; // 靠后放树
    }
};
Node ns[100005];
int pos, T, n, k, ts[300005], ls[300005], p[100005];
set<int> st;
void edit(int x)
{
    while (x <= pos)
    {
        ts[x]++;
        x += (x & -x);
    }
}
int query(int x)
{
    int res = 0;
    while (x)
    {
        res += ts[x];
        x -= (x & -x);
    }
    return res;
}
int main()
{
    cin >> T;
    while (T--)
    {
        pos = 0, st.clear(), fill(ts, ts + 300005, 0);
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> p[i];
            ls[++pos] = p[i];
        }
        for (int i = 1; i <= k; i++)
        {
            cin >> ns[i].l >> ns[i].r >> ns[i].t;
            ls[++pos] = ns[i].l, ls[++pos] = ns[i].r;
        }
        sort(ls + 1, ls + pos + 1);
        pos = unique(ls + 1, ls + pos + 1) - ls - 1;
        for (int i = 1; i <= n; i++)
        {
            st.emplace(lower_bound(ls + 1, ls + pos + 1, p[i]) - ls);
        }
        sort(ns + 1, ns + k + 1);
        for (int i = 1; i <= k; i++)
        {
            ns[i].l = lower_bound(ls + 1, ls + pos + 1, ns[i].l) - ls;
            ns[i].r = lower_bound(ls + 1, ls + pos + 1, ns[i].r) - ls;
            int t = ns[i].t - (query(ns[i].r) - query(ns[i].l - 1));
            auto it = prev(st.upper_bound(ns[i].r));
            for (int i = 1; i <= t; i++)
            {
                int p = *it;
                edit(p), it--;
                st.erase(p);
            }
        }
        cout << st.size() << endl;
    }
    return 0;
}
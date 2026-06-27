#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    long long q, lst, v;
    bool operator<(const Node &oth) const
    {
        return lst < oth.lst;
    }
};
Node ns[100005];
struct Sel
{
    long long q, v;
    bool operator<(const Sel &oth) const
    {
        return v > oth.v;
    }
};
priority_queue<Sel> pq;
int T;
int main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        while (pq.size())
        {
            pq.pop();
        }
        long long d, n, x, q, l, v;
        cin >> d >> n >> x;
        for (int i = 1; i <= n; i++)
        {
            cin >> q >> l >> v;
            ns[i] = Node{q, d - l, v};
        }
        sort(ns + 1, ns + n + 1);
        long long ans = 0, cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (ns[i].lst < 0)
            {
                continue;
            }
            pq.push(Sel{ns[i].q, ns[i].v});
            ans += ns[i].q * ns[i].v, cnt += ns[i].q;
            long long delta = cnt - ns[i].lst * x;
            while (delta > 0)
            {
                Sel now = pq.top();
                pq.pop();
                if (delta > now.q)
                {
                    ans -= now.q * now.v;
                    delta -= now.q, cnt -= now.q;
                }
                else
                {
                    ans -= delta * now.v;
                    cnt -= delta;
                    pq.push(Sel{now.q - delta, now.v});
                    delta = 0;
                }
            }
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
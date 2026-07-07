#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    long long s, t, lst;
    bool operator<(const Node &oth) const
    {
        return lst < oth.lst;
    }
};
Node ns[200005];
int T, n;
priority_queue<long long> pq;
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> ns[i].s >> ns[i].t;
            ns[i].lst = ns[i].s + ns[i].t;
        }
        sort(ns + 1, ns + 1 + n);
        long long tot = 0;
        for (int i = 1; i <= n; i++)
        {
            tot += ns[i].t, pq.push(ns[i].t);
            while (pq.size() && tot > ns[i].lst)
            {
                tot -= pq.top(), pq.pop();
            }
        }
        cout << pq.size() << endl;
        while (pq.size())
        {
            pq.pop();
        }
    }
    return 0;
}
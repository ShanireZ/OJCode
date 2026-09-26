#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    long long v, x;
    bool operator<(const Node &oth) const
    {
        return v < oth.v;
    }
};
Node ns[200005];
long long n, ans, tc[50005], tx[50005];
void edit(int x)
{
    long long p = x;
    while (x <= 50000)
    {
        tc[x]++, tx[x] += p;
        x += (x & -x);
    }
}
pair<long long, long long> query(int x)
{
    long long resc = 0, resx = 0;
    while (x > 0)
    {
        resc += tc[x], resx += tx[x];
        x -= (x & -x);
    }
    return {resc, resx};
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].v >> ns[i].x;
    }
    sort(ns + 1, ns + n + 1);
    for (int i = 1; i <= n; i++)
    {
        pair<long long, long long> res = query(ns[i].x);
        ans += ns[i].v * (ns[i].x * res.first - res.second);
        pair<long long, long long> res2 = query(50000);
        ans += ns[i].v * ((res2.second - res.second) - ns[i].x * (res2.first - res.first));
        edit(ns[i].x);
    }
    cout << ans % 998244353 << endl;
    return 0;
}
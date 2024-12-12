#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int p, c;
    bool operator<(const Node &oth) const
    {
        return p < oth.p;
    }
};
Node ns[100005];
struct Car
{
    int a, b;
    bool operator<(const Car &oth) const
    {
        return (a - b) > (oth.a - oth.b);
    }
};
Car cs[100005];
int main()
{
    int n, m, x;
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].p >> ns[i].c;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> cs[i].a >> cs[i].b;
    }
    sort(ns + 1, ns + n + 1), sort(cs + 1, cs + m + 1);
    long long res = 0; // 2xb+2p(a-b) ---> p小的配(a-b)大的,p大的配(a-b)小的
    for (int i = 1, p1 = 1; cs[p1].a - cs[p1].b >= 0; p1++)
    {
        res += 2ll * x * cs[p1].b + 2ll * ns[i].p * (cs[p1].a - cs[p1].b);
        ns[i].c--, i += (ns[i].c == 0);
    }
    for (int i = n, p2 = m; cs[p2].a - cs[p2].b < 0; p2--)
    {
        res += 2ll * x * cs[p2].b + 2ll * ns[i].p * (cs[p2].a - cs[p2].b);
        ns[i].c--, i -= (ns[i].c == 0);
    }
    cout << res << endl;
    return 0;
}
#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int g, s, b, id;
};
Node ns[200005];
int n, ans[200005];
bool cmpg(Node a, Node b)
{
    return a.g > b.g;
}
bool cmps(Node a, Node b)
{
    return a.s > b.s;
}
bool cmpb(Node a, Node b)
{
    return a.b > b.b;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].g >> ns[i].s >> ns[i].b;
        ns[i].id = i, ans[i] = 1e9;
    }
    sort(ns + 1, ns + n + 1, cmpg);
    for (int i = 1, rk = 1; i <= n; i++)
    {
        if (ns[i - 1].g != ns[i].g)
        {
            rk = i;
        }
        ans[ns[i].id] = min(ans[ns[i].id], rk);
    }
    sort(ns + 1, ns + n + 1, cmps);
    for (int i = 1, rk = 1; i <= n; i++)
    {
        if (ns[i - 1].s != ns[i].s)
        {
            rk = i;
        }
        ans[ns[i].id] = min(ans[ns[i].id], rk);
    }
    sort(ns + 1, ns + n + 1, cmpb);
    for (int i = 1, rk = 1; i <= n; i++)
    {
        if (ns[i - 1].b != ns[i].b)
        {
            rk = i;
        }
        ans[ns[i].id] = min(ans[ns[i].id], rk);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << '\n';
    }
    return 0;
}
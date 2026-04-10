#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int id, a, b, delta;
};
Node ns[1005];
int n, ans[1005];
bool cmpa(Node x, Node y)
{
    return x.a > y.a;
}
bool cmpb(Node x, Node y)
{
    return x.b > y.b;
}
bool cmpd(Node x, Node y)
{
    if (x.delta == y.delta)
    {
        return x.b > y.b;
    }
    return x.delta > y.delta;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].a;
        ns[i].id = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].b;
    }
    sort(ns + 1, ns + n + 1, cmpa);
    for (int i = 1; i <= n; i++)
    {
        ns[i].delta = i;
    }
    sort(ns + 1, ns + n + 1, cmpb);
    for (int i = 1; i <= n; i++)
    {
        ns[i].delta -= i;
    }
    sort(ns + 1, ns + n + 1, cmpd);
    for (int i = 1; i <= n; i++)
    {
        ans[ns[i].id] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
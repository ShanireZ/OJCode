#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int v, p;
};
Node ns[100005];
bool cmp(Node a, Node b)
{
    if (a.v == b.v)
    {
        return a.p < b.p;
    }
    return a.v < b.v;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].v;
        ns[i].p = i;
    }
    sort(ns + 1, ns + n + 1, cmp);
    int v = ns[1].v, ans = 1e9;
    for (int i = 2; i <= n; i++)
    {
        if (v == ns[i].v)
        {
            ans = min(ans, ns[i].p - ns[i - 1].p);
        }
    }
    cout << ans << endl;
    return 0;
}
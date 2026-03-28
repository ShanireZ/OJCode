#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int a, w;
};
Node ns[200005];
int n;
bool cmp(Node a, Node b)
{
    if (a.w == b.w)
    {
        return a.a < b.a;
    }
    return a.w < b.w;
}
int count(int x)
{
    int mx = 0, now = 0;
    while (x)
    {
        x % 2 == 1 ? now++ : now = 0;
        x /= 2, mx = max(mx, now);
    }
    return mx;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].a;
        ns[i].w = count(ns[i].a);
    }
    sort(ns + 1, ns + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        cout << ns[i].a << " ";
    }
    return 0;
}
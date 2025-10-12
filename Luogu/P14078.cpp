#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int x, t;
};
Node ns[100005];
int n, pos, dp[100005];
bool cmp(Node a, Node b)
{
    if (a.x == b.x)
    {
        return a.t < b.t;
    }
    return a.x < b.x;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].x >> ns[i].t;
    }
    sort(ns + 1, ns + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        int v = ns[i].t - ns[i].x;
        if (v < 0)
        {
            continue;
        }
        int p = upper_bound(dp + 1, dp + 1 + pos, v) - dp;
        dp[p] = v, pos = max(pos, p);
    }
    cout << pos << endl;
    return 0;
}
#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int cost, v;
    double g;
};
Node ns[105];
bool cmp(Node a, Node b)
{
    return a.g > b.g;
}
int ans, t, m;
int make_g(int now, int rem)
{
    int tot = 0;
    for (int i = now + 1; i <= m; i++)
    {
        if (rem >= ns[i].cost)
        {
            tot += ns[i].v;
            rem -= ns[i].cost;
        }
        else
        {
            tot += rem * ns[i].g;
            break;
        }
    }
    return tot;
}
void dfs(int now, int rem, int tot)
{
    ans = max(ans, tot);
    if (now == m + 1)
    {
        return;
    }
    if (rem >= ns[now].cost)
    {
        dfs(now + 1, rem - ns[now].cost, tot + ns[now].v);
    }
    if (tot + make_g(now, rem) > ans)
    {
        dfs(now + 1, rem, tot);
    }
}
int main()
{
    cin >> t >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> ns[i].cost >> ns[i].v;
        ns[i].g = 1.0 * ns[i].v / ns[i].cost;
    }
    sort(ns + 1, ns + 1 + m, cmp);
    dfs(1, t, 0);
    cout << ans << endl;
    return 0;
}
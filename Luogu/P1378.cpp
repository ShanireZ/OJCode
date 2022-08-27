#include <cmath>
#include <iostream>
using namespace std;
struct Node
{
    double x, y;
};
Node ns[10];
int n, vis[10];
double ans, rd[10], xa, ya, xb, yb;
void count(int now)
{
    double r = min(min(abs(ns[now].x - xa), abs(ns[now].x - xb)), min(abs(ns[now].y - ya), abs(ns[now].y - yb)));
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            continue;
        }
        double d = sqrt((ns[now].x - ns[i].x) * (ns[now].x - ns[i].x) + (ns[now].y - ns[i].y) * (ns[now].y - ns[i].y));
        if (d <= rd[i])
        {
            r = 0;
            break;
        }
        r = min(r, d - rd[i]);
    }
    rd[now] = r;
}
void dfs(int cnt, double tot)
{
    if (cnt > n)
    {
        ans = max(ans, tot);
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
        {
            continue;
        }
        count(i);
        vis[i] = 1;
        dfs(cnt + 1, tot + 3.1415926 * rd[i] * rd[i]);
        vis[i] = 0;
    }
}
int main()
{
    cin >> n >> xa >> ya >> xb >> yb;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].x >> ns[i].y;
    }
    dfs(1, 0);
    cout << int(abs((xa - xb) * (ya - yb)) - ans + 0.5) << endl;
    return 0;
}
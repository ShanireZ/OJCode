#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
struct Node
{
    int x, y;
};
Node ns[1005];
int g[1005];
struct Line
{
    int a, b;
    double dis;
};
Line ls[500005];
bool cmp(Line a, Line b)
{
    return a.dis < b.dis;
}
int dfs(int a)
{
    if (a != g[a])
    {
        g[a] = dfs(g[a]);
    }
    return g[a];
}
int main()
{
    int n, k, pos = 1;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        g[i] = i;
        cin >> ns[i].x >> ns[i].y;
        for (int j = 1; j < i; j++)
        {
            ls[pos].a = i;
            ls[pos].b = j;
            ls[pos++].dis = sqrt(pow(ns[i].x - ns[j].x, 2) + pow(ns[i].y - ns[j].y, 2));
        }
    }
    sort(ls + 1, ls + pos, cmp);
    int tot = 0;
    for (int i = 1; i < pos; i++)
    {
        int ga = dfs(ls[i].a);
        int gb = dfs(ls[i].b);
        if (ga != gb)
        {
            tot++;
            if (tot == n - k + 1)
            {
                cout << fixed << setprecision(2) << ls[i].dis;
            }
            g[ga] = gb;
        }
    }
    return 0;
}
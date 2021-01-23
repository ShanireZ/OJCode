#include <iostream>
#include <algorithm>
using namespace std;
struct Price
{
    int x, y, v;
};
bool cmp(Price a, Price b)
{
    return a.v < b.v;
}
Price p[125005];
int g[505];
int dfs(int x)
{
    if (g[x] != x)
    {
        g[x] = dfs(g[x]);
    }
    return g[x];
}
int main()
{
    int a, b, n = 1;
    cin >> a >> b;
    for (int j = 1; j <= b; j++)
    {
        p[n].x = 0;
        p[n].y = j;
        p[n++].v = a;
    }
    for (int i = 1; i <= b; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            int tmp;
            cin >> tmp;
            if (i < j && tmp < a && tmp != 0)
            {
                p[n].x = i;
                p[n].y = j;
                p[n++].v = tmp;
            }
        }
        g[i] = i;
    }
    sort(p + 1, p + n, cmp);
    int cost = 0, tot = 0;
    for (int i = 1; i <= n && tot < b; i++)
    {
        int gx = dfs(p[i].x);
        int gy = dfs(p[i].y);
        if (gx != gy)
        {
            cost += p[i].v;
            g[gx] = gy;
            tot++;
        }
    }
    cout << cost;
    return 0;
}
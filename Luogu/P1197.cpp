#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int g[400005];
vector<int> way[400005];
int closed[400005];
int state[400005];
int area;
int dfn(int x)
{
    if (x != g[x])
    {
        g[x] = dfn(g[x]);
    }
    return g[x];
}
void link(int x)
{
    for (int i = 0; i < way[x].size(); i++)
    {
        int to = way[x][i];
        if (g[to] != -1)
        {
            int gx = dfn(x), gy = dfn(to);
            if (gx != gy)
            {
                area--;
                g[gy] = gx;
            }
        }
    }
}
int main()
{
    int n, m, k;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        g[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        way[x].push_back(y);
        way[y].push_back(x);
    }
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> closed[i];
        g[closed[i]] = -1;
    }
    area = n - k;
    for (int i = 0; i < n; i++)
    {
        if (g[i] != -1)
        {
            link(i);
        }
    }
    state[k] = area;
    for (int i = k; i >= 1; i--)
    {
        int id = closed[i];
        g[id] = id;
        area++;
        link(id);
        state[i - 1] = area;
    }
    for (int i = 0; i <= k; i++)
    {
        cout << state[i] << endl;
    }
    return 0;
}
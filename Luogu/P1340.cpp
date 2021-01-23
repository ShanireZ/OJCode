#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int g[205], n, m, trig, opt[6005];
int dfn(int x)
{
    if (x != g[x])
    {
        g[x] = dfn(g[x]);
    }
    return g[x];
}
struct Way
{
    int x, y, w, t, usd;
};
bool cmp(Way x, Way y)
{
    return x.w < y.w;
}
vector<Way> way;
void kruskal(int time)
{
    for (int i = 1; i <= n; i++)
    {
        g[i] = i;
    }
    for (int i = 0; i < way.size(); i++)
    {
        way[i].usd = 0;
    }
    int cnt = 0, d = 0;
    for (int i = 0; cnt != n - 1 && i < way.size(); i++)
    {
        if (way[i].t > time)
        {
            continue;
        }
        int gx = dfn(way[i].x);
        int gy = dfn(way[i].y);
        if (gx != gy)
        {
            cnt++;
            g[gx] = gy;
            way[i].usd = 1;
            d += way[i].w;
        }
    }
    if (cnt == n - 1)
    {
        opt[time] = d;
    }
}
int main()
{
    memset(opt, -1, sizeof(opt));
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        Way tmp;
        cin >> tmp.x >> tmp.y >> tmp.w;
        tmp.t = i, tmp.usd = 0;
        way.push_back(tmp);
    }
    sort(way.begin(), way.end(), cmp);
    for (int i = m; i >= 1; i--)
    {
        if (trig == 1) //全都是-1了
        {
            continue;
        }
        int check = 1; //和上次相比最小生成树有没有改变
        for (int j = 0; j < way.size(); j++)
        {
            if (way[j].usd == 1 && way[j].t > i)
            {
                check = 0;
                break;
            }
        }
        if (check == 1 && i != m)
        {
            opt[i] = opt[i + 1];
            continue;
        }
        kruskal(i);
    }
    for (int i = 1; i <= m; i++)
    {
        cout << opt[i] << endl;
    }
    return 0;
}
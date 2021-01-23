#include <iostream>
#include <algorithm>
using namespace std;
struct Relate
{
    int a, b, c;
};
Relate rel[100005];
int g[40005];
bool cmp(Relate a, Relate b)
{
    return a.c > b.c;
}
int dfn(int x)
{
    if (x != g[x])
    {
        g[x] = dfn(g[x]);
    }
    return g[x];
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * 2; i++)
    {
        g[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> rel[i].a >> rel[i].b >> rel[i].c;
    }
    sort(rel + 1, rel + 1 + m, cmp);
    for (int i = 1; i <= m; i++)
    {
        int gx = dfn(rel[i].a), gy = dfn(rel[i].b);
        int fgx = dfn(rel[i].a + n), fgy = dfn(rel[i].b + n);
        if (gx == gy) //!已在同一组 必然会冲突 此时值为最大值的最小情况
        {
            cout << rel[i].c;
            return 0;
        }
        else //!不在同一组 gx与gy为敌人 gx合并敌人组gy gy合并敌人组gx 敌人的敌人合并在同一组
        {
            g[fgy] = gx;
            g[fgx] = gy;
        }
    }
    cout << 0;
    return 0;
}
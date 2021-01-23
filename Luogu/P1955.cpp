#include <iostream>
#include <algorithm>
using namespace std;
struct Relate
{
    int a, b, e;
};
Relate rel[1000005]; //存储关系
int g[2000005];      //并查集
int ranks[2000005];  //离散化
bool cmp(Relate x, Relate y)
{
    return x.e > y.e;
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
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n, trig = 1, p = 1;
        cin >> n;
        for (int j = 1; j <= n; j++)
        {
            cin >> rel[j].a >> rel[j].b >> rel[j].e;
            ranks[p++] = rel[j].a;
            ranks[p++] = rel[j].b;
        }
        //!数据范围过大但量不多 离散化 排序-去重-映射
        sort(ranks + 1, ranks + p);                         //!排序
        int m = unique(ranks + 1, ranks + p) - (ranks + 1); //!去重
        for (int j = 1; j <= n; j++)                        //!逐一映射
        {
            rel[j].a = lower_bound(ranks + 1, ranks + 1 + m, rel[j].a) - ranks;
            rel[j].b = lower_bound(ranks + 1, ranks + 1 + m, rel[j].b) - ranks;
            g[rel[j].a] = rel[j].a; //!并查集初始化
            g[rel[j].b] = rel[j].b;
        }
        sort(rel + 1, rel + 1 + n, cmp); //!先处理相同-合并 再处理不同-检查冲突
        for (int j = 1; j <= n; j++)
        {
            int e = rel[j].e, ga = dfn(rel[j].a), gb = dfn(rel[j].b);
            if (e == 1 && ga != gb) //!需要相等 但不在一组 合并
            {
                g[gb] = ga;
            }
            else if (e == 0 && ga == gb) //!需要不等 但已在一组 不成立
            {
                trig = 0;
                break;
            }
        }
        if (trig)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
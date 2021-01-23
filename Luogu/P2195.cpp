#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct Node
{
    vector<int> ways;
    int g, dis, vis, step;
    //g为并查集 dis为该集合的直径长度 vis为找直径时遍历标记 step为找直径时每点步数
};
Node ns[300005];
queue<int> pt;
int dfn(int x) //并查集查询
{
    if (x != ns[x].g)
    {
        ns[x].g = dfn(ns[x].g);
    }
    return ns[x].g;
}
int bfs(int x, int check) //两次遍历寻找直径长度
{
    int maxp = x, maxd = 0;
    pt.push(x);
    ns[x].vis++;
    ns[x].step = 0;
    while (pt.size())
    {
        int from = pt.front();
        pt.pop();
        for (int j = 0; j < ns[from].ways.size(); j++)
        {
            int to = ns[from].ways[j];
            if (ns[to].vis != check)
            {
                pt.push(to);
                ns[to].vis++;
                ns[to].step = ns[from].step + 1;
                if (ns[to].step > maxd)
                {
                    maxd = ns[to].step;
                    maxp = to;
                }
            }
        }
    }
    return maxp;
}
int read() //快读
{
    char ch = getchar();
    while ((ch > '9' || ch < '0') && ch != '-')
    {
        ch = getchar();
    }
    int t = 1, n = 0;
    if (ch == '-')
    {
        t = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        n = n * 10 + ch - '0';
        ch = getchar();
    }
    return n * t;
}
int main()
{
    int n = read(), m = read(), q = read(), opt, x, y;
    for (int i = 1; i <= n; i++) //并查集初始化
    {
        ns[i].g = i;
    }
    for (int i = 1; i <= m; i++) //读入边关系 合并并查集
    {
        x = read(), y = read();
        ns[x].ways.push_back(y);
        ns[y].ways.push_back(x);
        int gx = dfn(x), gy = dfn(y);
        ns[gx].g = gy;
    }
    for (int i = 1; i <= n; i++) //计算每个集合的直径长度
    {
        if (ns[i].g != i || ns[i].ways.size() == 0)
        {
            continue;
        }
        int pos = bfs(i, 1);
        pos = bfs(pos, 2);
        ns[i].dis = ns[pos].step;
    }
    for (int i = 1; i <= q; i++) //处理所有操作
    {
        opt = read(), x = read();
        if (opt == 1) //输出x所在集合的直径长度
        {
            int gx = dfn(x);
            printf("%d\n", ns[gx].dis);
        }
        else //合并并查集 更新集合的直径长度
        {
            y = read();
            int gx = dfn(x), gy = dfn(y);
            if (gx == gy)
            {
                continue;
            }
            //两集合合并 新直径长度有三种情况
            //1.原集合X的直径长度 2.原集合Y的直径长度
            //3.两集合的直径中点连线 1 + X直径/2 + Y直径/2
            //因为该题中所有路径长度都为1 所以中点为最优连线点
            int d = (ns[gx].dis + 1) / 2 + (ns[gy].dis + 1) / 2 + 1;
            ns[gy].dis = max(ns[gx].dis, ns[gy].dis);
            ns[gy].dis = max(ns[gy].dis, d);
            ns[gx].g = gy;
        }
    }
    return 0;
}
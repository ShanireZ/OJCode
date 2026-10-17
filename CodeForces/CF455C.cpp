#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct Node
{
    vector<int> ways;
    int g, dis, vis, step;
    //g為並查集 dis為該集合的直徑長度 vis為找直徑時遍歷標記 step為找直徑時每點步數
};
Node ns[300005];
queue<int> pt;
int dfn(int x) //並查集查詢
{
    if (x != ns[x].g)
    {
        ns[x].g = dfn(ns[x].g);
    }
    return ns[x].g;
}
int bfs(int x, int check) //兩次遍歷尋找直徑長度
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
int read() //快讀
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
    for (int i = 1; i <= n; i++) //並查集初始化
    {
        ns[i].g = i;
    }
    for (int i = 1; i <= m; i++) //讀入邊關係 合併並查集
    {
        x = read(), y = read();
        ns[x].ways.push_back(y);
        ns[y].ways.push_back(x);
        int gx = dfn(x), gy = dfn(y);
        ns[gx].g = gy;
    }
    for (int i = 1; i <= n; i++) //計算每個集合的直徑長度
    {
        if (ns[i].g != i || ns[i].ways.size() == 0)
        {
            continue;
        }
        int pos = bfs(i, 1);
        pos = bfs(pos, 2);
        ns[i].dis = ns[pos].step;
    }
    for (int i = 1; i <= q; i++) //處理所有操作
    {
        opt = read(), x = read();
        if (opt == 1) //輸出x所在集合的直徑長度
        {
            int gx = dfn(x);
            printf("%d\n", ns[gx].dis);
        }
        else //合併並查集 更新集合的直徑長度
        {
            y = read();
            int gx = dfn(x), gy = dfn(y);
            if (gx == gy)
            {
                continue;
            }
            //兩集合合併 新直徑長度有三種情況
            //1.原集合X的直徑長度 2.原集合Y的直徑長度
            //3.兩集合的直徑中點連線 1 + X直徑/2 + Y直徑/2
            //因為該題中所有路徑長度都為1 所以中點為最優連線點
            int d = (ns[gx].dis + 1) / 2 + (ns[gy].dis + 1) / 2 + 1;
            ns[gy].dis = max(ns[gx].dis, ns[gy].dis);
            ns[gy].dis = max(ns[gy].dis, d);
            ns[gx].g = gy;
        }
    }
    return 0;
}
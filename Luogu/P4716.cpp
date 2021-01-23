#include <cstdio>
#include <cstring>
using namespace std;
struct Edge
{
    int u, v, w;
};
Edge es[10005];
int ine[105], from[105], vis[105], gid[105];
int read();
long long ZL(int n, int m, int root)
{
    long long ans = 0;
    while (true)
    {
        //? 1.找到最短边集合E
        for (int i = 1; i <= n; i++) //ine表示每点的最小入边
        {
            ine[i] = 1234567; //初始化ine为最大值
        }
        for (int i = 1; i <= m; i++) //遍历更新ine和fa
        {
            int u = es[i].u, v = es[i].v, w = es[i].w;
            if (w < ine[v] && u != v) //去除自环
            {
                ine[v] = w;
                from[v] = u; //fa表示每点最小入边的源
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (i != root && ine[i] == 1234567) //根节点以外 存在无入边的区域 不连通
            {
                return -1;
            }
        }
        //? 2.判断E中是否存在环 存在环->缩点 不存在环->得到答案
        int cnt = 0;
        memset(gid, 0, sizeof(gid));
        memset(vis, 0, sizeof(vis));
        ine[root] = 0; //根节点无入边
        for (int i = 1; i <= n; i++)
        {
            ans += ine[i];
            int p = i;
            //终止条件 1.当前节点属于其他环 2.遍历到了根节点 3.回到了此次遍历经过的点说明出现了环
            //gid表示点所在环的编号->可引申为强连通分量的编号
            while (gid[p] == 0 && p != root && vis[p] != i)
            {
                vis[p] = i;  //v表示从i出发已经遍历过该点
                p = from[p]; //继续朝上找
            }
            if (p != root && gid[p] == 0) //非根节点且不在其他环中
            {
                gid[p] = ++cnt; //对环内所有点的gid标记 同时cnt也表示环的个数
                int x = from[p];
                while (x != p)
                {
                    gid[x] = cnt;
                    x = from[x];
                }
            }
        }
        if (cnt == 0) //不存在环->终止循环得到答案
        {
            break;
        }
        //? 3.进行缩点构建新图 然后重新再来一遍
        for (int i = 1; i <= n; i++) //不在环内单独的点也算是一个强连通
        {
            if (gid[i] == 0)
            {
                gid[i] = ++cnt;
            }
        }
        for (int i = 1; i <= m; i++) //构建新图 重新连边
        {
            int u = es[i].u, v = es[i].v, w = es[i].w;
            es[i].u = gid[u], es[i].v = gid[v]; //缩点
            //朱刘算法: u v不同环 u->v的w 变为w - ine[v]
            //原理解释参考:
            //1. http://www.manongjc.com/detail/18-amxvfeiiifzyove.html
            //2. https://www.cnblogs.com/ww3113306/p/9158404.html
            if (gid[u] != gid[v])
            {
                es[i].w = w - ine[v];
            }
        }
        n = cnt;          //更新下一轮点的数目为本轮强连通数目
        root = gid[root]; //root更新
    }
    return ans;
}
int main()
{
    int n = read(), m = read(), root = read();
    for (int i = 1; i <= m; i++)
    {
        es[i].u = read(), es[i].v = read(), es[i].w = read();
    }
    long long ans = ZL(n, m, root);
    printf("%lld", ans);
    return 0;
}
int read()
{
    int ans = 0, type = 1;
    char ch = getchar();
    while (ch != '-' && ch > '9' || ch < '0')
    {
        ch = getchar();
    }
    if (ch == '-')
    {
        type = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * type;
}
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
        //? 1.找到最短邊集合E
        for (int i = 1; i <= n; i++)
        {                     //ine表示每點的最小入邊
            ine[i] = 1234567; //初始化ine為最大值
        }

        for (int i = 1; i <= m; i++)
        { //遍歷更新ine和fa
            int u = es[i].u, v = es[i].v, w = es[i].w;

            if (w < ine[v] && u != v)
            { //去除自環
                ine[v] = w;
                from[v] = u; //fa表示每點最小入邊的源
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (i != root && ine[i] == 1234567)
            { //根節點以外 存在無入邊的區域 不連通
                return -1;
            }
        }

        //? 2.判斷E中是否存在環 存在環->縮點 不存在環->得到答案
        int cnt = 0;
        memset(gid, 0, sizeof(gid));
        memset(vis, 0, sizeof(vis));
        ine[root] = 0; //根節點無入邊

        for (int i = 1; i <= n; i++)
        {
            ans += ine[i];
            int p = i;

            //終止條件 1.當前節點屬於其他環 2.遍歷到了根節點 3.回到了此次遍歷經過的點說明出現了環
            //gid表示點所在環的編號->可引申為強連通分量的編號
            while (gid[p] == 0 && p != root && vis[p] != i)
            {
                vis[p] = i;  //v表示從i出發已經遍歷過該點
                p = from[p]; //繼續朝上找
            }

            if (p != root && gid[p] == 0)
            {                   //非根節點且不在其他環中
                gid[p] = ++cnt; //對環內所有點的gid標記 同時cnt也表示環的個數
                int x = from[p];

                while (x != p)
                {
                    gid[x] = cnt;
                    x = from[x];
                }
            }
        }

        if (cnt == 0)
        { //不存在環->終止循環得到答案
            break;
        }

        //? 3.進行縮點建置新圖 然後重新再來一遍
        for (int i = 1; i <= n; i++)
        { //不在環內單獨的點也算是一個強連通
            if (gid[i] == 0)
            {
                gid[i] = ++cnt;
            }
        }

        for (int i = 1; i <= m; i++)
        { //建置新圖 重新連邊
            int u = es[i].u, v = es[i].v, w = es[i].w;
            es[i].u = gid[u], es[i].v = gid[v]; //縮點

            //朱劉演算法: u v不同環 u->v的w 變為w - ine[v]
            //原理解釋參考:
            //1. http://www.manongjc.com/detail/18-amxvfeiiifzyove.html
            //2. https://www.cnblogs.com/ww3113306/p/9158404.html
            if (gid[u] != gid[v])
            {
                es[i].w = w - ine[v];
            }
        }

        n = cnt;          //更新下一輪點的數目為本輪強連通數目
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
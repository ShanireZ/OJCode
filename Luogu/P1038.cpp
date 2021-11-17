#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int read()
{
    int ans = 0, t = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
        {
            t = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * t;
}
struct Edge
{
    int to, w;
    Edge(int To, int W)
    {
        to = To, w = W;
    }
};
struct Node
{
    int c, u, ind;
    vector<Edge> es;
} ns[105];
queue<int> tp;
int main()
{
    int n = read(), p = read();
    for (int i = 1; i <= n; i++)
    {
        ns[i].c = read(), ns[i].u = read();
    }
    for (int i = 1; i <= p; i++)
    {
        int u = read(), v = read(), w = read();
        ns[u].es.push_back(Edge(v, w));
    }
    for (int i = 1; i <= n; i++)
    {
        if (ns[i].c > 0) //激活的输入层
        {
            tp.push(i);
            for (int j = 0; j < ns[i].es.size(); j++) //增加下层入度
            {
                ns[ns[i].es[j].to].ind++;
            }
        }
        else
        {
            ns[i].c = -ns[i].u;
        }
    }
    while (tp.size())
    {
        int from = tp.front();
        tp.pop();
        for (int i = 0; i < ns[from].es.size(); i++)
        {
            int to = ns[from].es[i].to, w = ns[from].es[i].w;
            ns[to].c += w * ns[from].c;
            ns[to].ind--;
            if (ns[to].ind == 0 && ns[to].c > 0)
            {
                tp.push(to);
                for (int j = 0; j < ns[to].es.size(); j++) //增加下层入度
                {
                    ns[ns[to].es[j].to].ind++;
                }
            }
        }
    }
    int trig = 0;
    for (int i = 1; i <= n; i++)
    {
        if (ns[i].es.size() == 0 && ns[i].c > 0) //激活的输出层
        {
            printf("%d %d\n", i, ns[i].c);
            trig = 1;
        }
    }
    if (trig == 0)
    {
        printf("NULL\n");
    }
    return 0;
}
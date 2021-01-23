#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
long long read();
struct Node
{
    long long v, mul, cur; //! v加法操作值 mul乘法操作值 cur累计系数
    int tp, p, ind;        //! tp操作类型 p操作位置 ind入度
    vector<int> to;        //! 子操作编号
};
Node ns[100005];
long long val[100005], mod = 998244353, now;
int n, m, q, topo[100005], f[100005], pos;
queue<int> pt;

void topology()
{
    //! 拓扑排序
    for (int i = 1; i <= m; i++)
    {
        if (ns[i].ind == 0)
        {
            pt.push(i);
        }
    }
    while (pt.size())
    {
        int from = pt.front();
        pt.pop();
        topo[++pos] = from;
        for (int i = ns[from].to.size() - 1; i >= 0; i--)
        {
            int to = ns[from].to[i];
            ns[to].ind--;
            if (ns[to].ind == 0)
            {
                pt.push(to);
            }
        }
    }
    //! 根据拓扑序 计算每个第3类操作的mul
    for (int i = m; i >= 1; i--)
    {
        int from = topo[i];
        for (int j = ns[from].to.size() - 1; j >= 0; j--)
        {
            int to = ns[from].to[j];
            ns[from].mul = ns[from].mul * ns[to].mul % mod;
        }
    }
}

void makecur()
{
    //! 根据实际操作 得到每个操作的后置系数
    now = 1;
    for (int i = q; i >= 1; i--)
    {
        int x = f[i];
        ns[x].cur = (ns[x].cur + now) % mod;
        now = now * ns[x].mul % mod;
    }
    //! 将系数下传至第1类操作的节点
    for (int i = 1; i <= m; i++)
    {
        int x = topo[i];
        long long nowx = 1;
        for (int j = ns[x].to.size() - 1; j >= 0; j--)
        {
            int to = ns[x].to[j];
            ns[to].cur = (ns[to].cur + ns[x].cur * nowx % mod) % mod;
            nowx = nowx * ns[to].mul % mod;
        }
    }
}

int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
    {
        val[i] = read();
    }
    m = read();
    for (int i = 1; i <= m; i++)
    {
        ns[i].tp = read();
        if (ns[i].tp == 1)
        {
            ns[i].mul = 1;
            ns[i].p = read();
            ns[i].v = read();
        }
        else if (ns[i].tp == 2)
        {
            ns[i].mul = read();
        }
        else
        {
            ns[i].mul = 1;
            int times = read();
            for (int j = 1; j <= times; j++)
            {
                int x = read();
                ns[i].to.push_back(x);
                ns[x].ind++;
            }
        }
    }
    topology();
    q = read();
    for (int i = 1; i <= q; i++)
    {
        f[i] = read();
    }
    makecur();
    for (int i = 1; i <= n; i++)
    {
        val[i] = val[i] * now % mod;
    }
    for (int i = 1; i <= m; i++)
    {
        if (ns[i].tp == 1)
        {
            int id = ns[i].p;
            val[id] = (val[id] + ns[i].v * ns[i].cur % mod) % mod;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%lld ", val[i]);
    }
    return 0;
}

long long read() //快读
{
    char ch = getchar();
    while ((ch > '9' || ch < '0') && ch != '-')
    {
        ch = getchar();
    }
    long long t = 1, n = 0;
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
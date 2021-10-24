#include <cstdio>
#include <algorithm>
using namespace std;
struct Node
{
    int v, id;
    bool operator<(const Node ano) const
    {
        if (v == ano.v)
        {
            return id < ano.id;
        }
        return v < ano.v;
    }
};
Node ns[8005];
int n, q, pos[8005]; //pos[i] 原数列第i个数 排序后第几名
void edit(int x, int v)
{
    int p = pos[x];
    int pre = ns[p].v;
    ns[p].v = v;
    if (pre > v) //数变小 向前
    {
        for (int i = p; i > 1; i--)
        {
            if ((ns[i].v < ns[i - 1].v) ||
                (ns[i].v == ns[i - 1].v && ns[i].id < ns[i - 1].id))
            {
                pos[ns[i - 1].id]++;
                pos[ns[i].id]--;
                swap(ns[i], ns[i - 1]);
            }
            else
            {
                break;
            }
        }
    }
    else if (pre < v) //数变大 向后
    {
        for (int i = p; i < n; i++)
        {
            if ((ns[i].v > ns[i + 1].v) ||
                (ns[i].v == ns[i + 1].v && ns[i].id > ns[i + 1].id))
            {
                pos[ns[i + 1].id]--;
                pos[ns[i].id]++;
                swap(ns[i], ns[i + 1]);
            }
            else
            {
                break;
            }
        }
    }
}
int read();
int main()
{
    n = read(), q = read();
    for (int i = 1; i <= n; i++)
    {
        ns[i].id = i;
        ns[i].v = read();
    }
    sort(ns + 1, ns + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        pos[ns[i].id] = i;
    }
    for (int i = 1; i <= q; i++)
    {
        int opt = read();
        if (opt == 1)
        {
            int x = read(), v = read();
            edit(x, v);
        }
        else
        {
            int x = read();
            printf("%d\n", pos[x]);
        }
    }
}
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
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct Node
{
    int x, y, g;
};
Node ns[505];
struct Edge
{
    int a, b;
    double dis;
    bool operator<(const Edge &another) const
    {
        return dis < another.dis;
    }
};
Edge es[250005];
int pos;
int dfn(int now)
{
    if (ns[now].g != now)
    {
        ns[now].g = dfn(ns[now].g);
    }
    return ns[now].g;
}
int read();
int main()
{
    int n = read(), k = read();
    for (int i = 1; i <= n; i++)
    {
        ns[i].g = i;
        ns[i].x = read(), ns[i].y = read();
        for (int j = 1; j < i; j++)
        {
            es[++pos].a = i;
            es[pos].b = j;
            es[pos].dis = sqrt(pow(ns[i].x - ns[j].x, 2) + pow(ns[i].y - ns[j].y, 2));
        }
    }
    sort(es + 1, es + 1 + pos);
    int cnt = n - k;
    for (int i = 1; i <= pos; i++)
    {
        int ga = dfn(es[i].a), gb = dfn(es[i].b);
        if (ga != gb)
        {
            ns[gb].g = ga;
            cnt--;
            if (cnt == 0)
            {
                printf("%.2lf", es[i].dis);
                break;
            }
        }
    }
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
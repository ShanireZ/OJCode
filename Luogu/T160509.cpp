#include <cstdio>
#include <algorithm>
using namespace std;
int read();
struct Node
{
    int id, k, t, gx;
};
bool cmp(Node a, Node b)
{
    if (a.gx == b.gx)
    {
        if (a.t == b.t)
        {
            return a.id < b.id;
        }
        return a.t > b.t;
    }
    return a.gx > b.gx;
}
Node ns[500005];
int main()
{
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        ns[i].id = i;
        ns[i].t = read(), ns[i].k = read();
        ns[i].gx = ns[i].t * ns[i].k;
    }
    sort(ns + 1, ns + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", ns[i].id);
    }
    return 0;
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
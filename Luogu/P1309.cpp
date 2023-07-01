#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int s, w, id;
};
Node ns[200005], win[100005], lose[100005];
bool cmp(Node a, Node b)
{
    if (a.s == b.s)
    {
        return a.id < b.id;
    }
    return a.s > b.s;
}
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}
int main()
{
    int n = read() * 2, r = read(), q = read();
    for (int i = 1; i <= n; i++)
    {
        ns[i].s = read(), ns[i].id = i;
    }
    for (int i = 1; i <= n; i++)
    {
        ns[i].w = read();
    }
    sort(ns + 1, ns + 1 + n, cmp);
    win[n / 2 + 1].s = -100, lose[n / 2 + 1].s = -100;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1, pos = 1; j <= n; j += 2, pos++)
        {
            if (ns[j].w > ns[j + 1].w)
            {
                ns[j].s++;
                win[pos] = ns[j], lose[pos] = ns[j + 1];
            }
            else
            {
                ns[j + 1].s++;
                win[pos] = ns[j + 1], lose[pos] = ns[j];
            }
        }
        int pw = 1, pl = 1;
        for (int j = 1; j <= n; j++)
        {
            ns[j] = (win[pw].s == lose[pl].s && win[pw].id < lose[pl].id || win[pw].s > lose[pl].s) ? win[pw++] : lose[pl++];
        }
    }
    printf("%d\n", ns[q].id);
    return 0;
}
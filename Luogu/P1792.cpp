#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
#define MX 200005
int read();
struct Node
{
    int a, l, r, vis;
};
Node ns[MX];
struct Plan
{
    int w, id;
    Plan(int W, int Id)
    {
        w = W, id = Id;
    }
    bool operator<(const Plan oth) const
    {
        return w < oth.w;
    }
};
priority_queue<Plan> q;
int main()
{
    int n = read(), m = read();
    if (m > n / 2)
    {
        printf("Error!\n");
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        ns[i].a = read();
        ns[i].l = i - 1, ns[i].r = i + 1;
        q.push(Plan(ns[i].a, i));
    }
    ns[1].l = n, ns[n].r = 1;
    int ans = 0, cnt = 0;
    while (cnt < m)
    {
        int now = q.top().id, w = q.top().w;
        q.pop();
        if (ns[now].vis == 1)
        {
            continue;
        }
        ans += w;
        ns[ns[now].l].vis = ns[ns[now].r].vis = 1;         // 两侧封禁
        ns[now].a = ns[ns[now].l].a + ns[ns[now].r].a - w; // 扩展区域
        ns[now].l = ns[ns[now].l].l, ns[now].r = ns[ns[now].r].r;
        ns[ns[now].l].r = ns[ns[now].r].l = now;
        q.push(Plan(ns[now].a, now)); // 加入新区域
        cnt++;
    }
    printf("%d\n", ans);
    return 0;
}
int read()
{
    int ans = 0, t = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
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
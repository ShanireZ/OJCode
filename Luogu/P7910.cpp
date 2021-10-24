#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int read();
int n, q, pos, tree[210005], all[210005], num[10005];
vector<int> link[210005];
int lowbit(int x)
{
    return x & -x;
}
void edit(int x, int add)
{
    while (x <= 210005)
    {
        tree[x] += add;
        x += lowbit(x);
    }
}
int query(int x)
{
    int ans = 0;
    while (x)
    {
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}
struct Qst
{
    int t, x, v;
};
Qst qst[200005];
int main()
{
    // freopen("sort4.in", "r", stdin);
    // freopen("sort4.out", "w", stdout);
    n = read(), q = read();
    for (int i = 1; i <= n; i++)
    {
        num[i] = read();
        all[pos++] = num[i];
    }
    for (int i = 1; i <= q; i++)
    {
        qst[i].t = read();
        qst[i].x = read();
        if (qst[i].t == 1)
        {
            qst[i].v = read();
            all[pos++] = qst[i].v;
        }
    }
    sort(all, all + pos);
    pos = unique(all, all + pos) - all;
    for (int i = 1; i <= n; i++)
    {
        num[i] = lower_bound(all, all + pos, num[i]) - all + 1;
        edit(num[i], 1);
        link[num[i]].push_back(i);
    }
    for (int i = 1; i <= q; i++)
    {
        if (qst[i].t == 1)
        {
            qst[i].v = lower_bound(all, all + pos, qst[i].v) - all + 1;
            int pre = num[qst[i].x];
            int now = qst[i].v;
            num[qst[i].x] = now;
            edit(pre, -1);
            edit(now, 1);
            int p = lower_bound(link[pre].begin(), link[pre].end(), qst[i].x) - link[pre].begin();
            link[pre].erase(link[pre].begin() + p);
            p = lower_bound(link[now].begin(), link[now].end(), qst[i].x) - link[now].begin();
            if (p == link[now].size())
            {
                link[now].push_back(qst[i].x);
            }
            else
            {
                link[now].insert(link[now].begin() + p, qst[i].x);
            }
        }
        else
        {
            int now = num[qst[i].x];
            int ans = query(now - 1);
            ans += lower_bound(link[now].begin(), link[now].end(), qst[i].x) - link[now].begin();
            printf("%d\n", ans + 1);
        }
    }
    return 0;
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
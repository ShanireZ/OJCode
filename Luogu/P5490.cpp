#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MX 100005
#define LC ns[now].lc
#define RC ns[now].rc
struct Line
{
    int x, down, up, opt;
    bool operator<(const Line oth) const
    {
        return x < oth.x;
    }
};
Line lines[MX * 2];
struct Node
{
    int lc, rc, t, len, v;
};
Node ns[MX * 8];
vector<int> ls;
int root, npos, read();
void maketree(int &now, int l, int r)
{
    now = ++npos;
    if (l == r)
    {
        ns[now].len = ls[l] - ls[l - 1];
        return;
    }
    int mid = (l + r) / 2;
    maketree(LC, l, mid), maketree(RC, mid + 1, r);
    ns[now].len = ns[LC].len + ns[RC].len;
}
void edit(int now, int l, int r, int x, int y, int k)
{
    if (x <= l && y >= r)
    {
        ns[now].t += k;
        ns[now].v = (ns[now].t ? ns[now].len : ns[LC].v + ns[RC].v);
        return;
    }
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        edit(LC, l, mid, x, y, k);
    }
    if (y > mid)
    {
        edit(RC, mid + 1, r, x, y, k);
    }
    ns[now].v = (ns[now].t ? ns[now].len : ns[LC].v + ns[RC].v);
}
int main()
{
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        int x1 = read(), y1 = read(), x2 = read(), y2 = read(), p1 = i * 2 - 1, p2 = i * 2;
        lines[p1] = Line{x1, y1, y2, 1}, lines[p2] = Line{x2, y1, y2, -1};
        ls.push_back(y1), ls.push_back(y2);
    }
    sort(ls.begin(), ls.end()), sort(lines + 1, lines + 1 + n * 2);
    int sz = ls.erase(unique(ls.begin(), ls.end()), ls.end()) - ls.begin();
    // 线段树1区间表示y轴0~1, ...., sz-1表示sz-2~sz-1
    maketree(root, 1, sz - 1);
    long long ans = 0, pre = 0;
    for (int i = 1; i <= n * 2; i++)
    {
        ans += (lines[i].x - pre) * ns[root].v, pre = lines[i].x;
        int down = lower_bound(ls.begin(), ls.end(), lines[i].down) - ls.begin();
        int up = lower_bound(ls.begin(), ls.end(), lines[i].up) - ls.begin();
        edit(root, 1, sz - 1, down + 1, up, lines[i].opt);
    }
    printf("%lld\n", ans);
    return 0;
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
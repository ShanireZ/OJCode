#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int lc, rc, v;
};
Node ns[40000000];
int n, m, pos, root[100005], p[100005];
int lowbit(int x)
{
    return x & -x;
}
int querytree(int now, int l, int r, int x, int y)
{
    if (now == 0)
    {
        return 0;
    }
    if (x <= l && y >= r)
    {
        return ns[now].v;
    }
    int mid = (l + r) / 2, ans = 0;
    if (x <= mid)
    {
        ans += querytree(ns[now].lc, l, mid, x, y);
    }
    if (y > mid)
    {
        ans += querytree(ns[now].rc, mid + 1, r, x, y);
    }
    return ans;
}
int query(int st, int ed, int x) // 查询st~ed中大于等于x的个数
{
    int ans = 0;
    for (int i = ed; i > 0; i -= lowbit(i))
    {
        ans += querytree(root[i], 1, n, x, n); // 加大于等于x的个数
    }
    for (int i = st - 1; i > 0; i -= lowbit(i))
    {
        ans -= querytree(root[i], 1, n, x, n); // 减大于等于x的个数
    }
    return ans;
}
void edittree(int &now, int l, int r, int x, int k)
{
    if (now == 0)
    {
        now = ++pos;
        ns[now].v = ns[now].lc = ns[now].rc = 0;
    }
    if (l == r)
    {
        ns[now].v += k;
        return;
    }
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        edittree(ns[now].lc, l, mid, x, k);
    }
    else
    {
        edittree(ns[now].rc, mid + 1, r, x, k);
    }
    ns[now].v = ns[ns[now].lc].v + ns[ns[now].rc].v;
}
void edit(int st, int x, int k) // 将st~n中x的出现次数+k
{
    for (int i = st; i <= n; i += lowbit(i))
    {
        edittree(root[i], 1, n, x, k); // 每个版本的x的次数+k
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while (scanf("%d %d", &n, &m) != EOF)
    {
        long long ans = 0;
        pos = 0;
        for (int i = 1; i <= n; i++)
        {
            root[i] = 0;
        }
        int x;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &x);
            p[x] = i;
            ans += query(1, i - 1, x); // 前方大于等于x的个数
            edit(i, x, 1);             // 从i位置起x出现次数+1
        }
        for (int i = 1; i <= m; i++)
        {
            printf("%lld\n", ans);
            scanf("%d", &x);
            edit(p[x], x, -1);                                    // 从p[x]起删除x
            ans -= query(1, p[x] - 1, x);                         // 前方大于等于x的数量
            ans -= query(p[x] + 1, n, 0) - query(p[x] + 1, n, x); // 后方小于x的数量
        }
    }
    return 0;
}
// TAG: 线段树 树状数组 树套树 动态可持久
// 树状数组维护版本，例如版本1表示第一个数字出现时的情况，版本4表示前4个数出现时的情况
// 后续利用版本可以进行差分操作，得到任意区间的情况
// 树状数组的每个点维护的是一个线段树，线段树的每个点维护的是一个数字出现的次数
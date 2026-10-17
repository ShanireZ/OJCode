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
int query(int st, int ed, int x) // 查詢st~ed中大於等於x的個數
{
    int ans = 0;
    for (int i = ed; i > 0; i -= lowbit(i))
    {
        ans += querytree(root[i], 1, n, x, n); // 加大於等於x的個數
    }
    for (int i = st - 1; i > 0; i -= lowbit(i))
    {
        ans -= querytree(root[i], 1, n, x, n); // 減大於等於x的個數
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
void edit(int st, int x, int k) // 將st~n中x的出現次數+k
{
    for (int i = st; i <= n; i += lowbit(i))
    {
        edittree(root[i], 1, n, x, k); // 每個版本的x的次數+k
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
            ans += query(1, i - 1, x); // 前方大於等於x的個數
            edit(i, x, 1);             // 從i位置起x出現次數+1
        }
        for (int i = 1; i <= m; i++)
        {
            printf("%lld\n", ans);
            scanf("%d", &x);
            edit(p[x], x, -1);                                    // 從p[x]起刪除x
            ans -= query(1, p[x] - 1, x);                         // 前方大於等於x的數量
            ans -= query(p[x] + 1, n, 0) - query(p[x] + 1, n, x); // 後方小於x的數量
        }
    }
    return 0;
}
// TAG: 線段樹 樹狀陣列 樹套樹 動態可持久
// 樹狀陣列維護版本，例如版本1表示第一個數字出現時的情況，版本4表示前4個數出現時的情況
// 後續利用版本可以進行差分操作，得到任意區間的情況
// 樹狀陣列的每個點維護的是一個線段樹，線段樹的每個點維護的是一個數字出現的次數
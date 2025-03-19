#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define MX 300005
struct Node
{
    int v, lc, rc, tag;
};
Node ns[MX * 2];
int a[MX], suml[MX], sumr[MX], c[MX], n, npos, root, ans;
vector<int> nums[MX];
void init(int &now, int l, int r)
{
    now = ++npos;
    if (l == r)
    {
        ns[now].v = suml[l];
        return;
    }
    int mid = (l + r) >> 1;
    init(ns[now].lc, l, mid), init(ns[now].rc, mid + 1, r);
    ns[now].v = max(ns[ns[now].lc].v, ns[ns[now].rc].v);
}
void pd(int now, int l, int r)
{
    int lc = ns[now].lc, rc = ns[now].rc, tag = ns[now].tag;
    ns[lc].tag += tag, ns[rc].tag += tag;
    ns[lc].v += tag, ns[rc].v += tag;
    ns[now].tag = 0;
}
void edit(int now, int l, int r, int x, int y)
{
    if (x <= l && y >= r)
    {
        ns[now].tag++, ns[now].v++;
        return;
    }
    pd(now, l, r);
    int mid = (l + r) >> 1;
    if (x <= mid)
    {
        edit(ns[now].lc, l, mid, x, y);
    }
    if (y > mid)
    {
        edit(ns[now].rc, mid + 1, r, x, y);
    }
    ns[now].v = max(ns[ns[now].lc].v, ns[ns[now].rc].v);
}
int query(int now, int l, int r, int x, int y)
{
    if (x <= l && y >= r)
    {
        return ns[now].v;
    }
    pd(now, l, r);
    int mid = (l + r) >> 1, res = 0;
    if (x <= mid)
    {
        res = max(res, query(ns[now].lc, l, mid, x, y));
    }
    if (y > mid)
    {
        res = max(res, query(ns[now].rc, mid + 1, r, x, y));
    }
    return res;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        c[a[i]]++, nums[a[i]].emplace_back(i);
        suml[i] = suml[i - 1] + (c[a[i]] == 1);
    }
    memset(c, 0, sizeof(c));
    for (int i = n; i >= 1; i--)
    {
        c[a[i]]++;
        sumr[i] = sumr[i + 1] + (c[a[i]] == 1);
    }
    init(root, 1, n);            // 线段树统计以x为中点分成两个区域时的最佳方案
    for (int i = 2; i <= n; i++) // 枚举区间[1,i]的右端i,找到将[1,i]分为两个区域时的最佳方案
    {
        int pos, p = lower_bound(nums[a[i]].begin(), nums[a[i]].end(), i) - nums[a[i]].begin();
        pos = (p == 0 ? 1 : nums[a[i]][p - 1]);
        edit(root, 1, n, pos, i - 1);
        ans = max(ans, query(root, 1, n, 1, i - 1) + sumr[i + 1]);
    }
    cout << ans << endl;
    return 0;
}
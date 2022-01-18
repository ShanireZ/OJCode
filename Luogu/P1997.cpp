#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
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
int n, q, sz, maxt, a[100005], cnt[200005], sum[100005], ans[200005];
struct Block
{
    int l, r, id;
    bool operator<(const Block oth) const
    {
        if (l / sz == oth.l / sz)
        {
            return r < oth.r;
        }
        return l < oth.l;
    }
};
Block blk[200005];
void add(int x)
{
    cnt[x]++;
    sum[cnt[x]]++;
    maxt = max(maxt, cnt[x]);
}
void del(int x)
{
    sum[cnt[x]]--;
    if (sum[cnt[x]] == 0 && maxt == cnt[x])
    {
        maxt--;
    }
    cnt[x]--;
}
int main()
{
    n = read(), q = read();
    sz = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        a[i] = read() + 100000;
    }
    for (int i = 1; i <= q; i++)
    {
        blk[i].id = i;
        blk[i].l = read(), blk[i].r = read();
    }
    sort(blk + 1, blk + 1 + q);
    int l = 1, r = 0;
    for (int i = 1; i <= q; i++)
    {
        while (blk[i].l < l)
            add(a[--l]);
        while (blk[i].l > l)
            del(a[l++]);
        while (blk[i].r < r)
            del(a[r--]);
        while (blk[i].r > r)
            add(a[++r]);
        ans[blk[i].id] = maxt;
    }
    for (int i = 1; i <= q; i++)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}
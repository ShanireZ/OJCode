#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int read();
int n, q, numsz, bklen, bksz, now = 1;
// numsz不重复数字个数 bklen块大小 bksz块总个数 now当前待处理询问编号
int all[100005], x[100005];
long long ans[100005], ts[100005];
// all离散用去重序列 x离散化后原序列 ans答案 ts统计出现次数
struct Quest
{
    int l, r, id;
    bool operator<(const Quest oth) const
    {
        if (l / bklen == oth.l / bklen)
        {
            return r < oth.r;
        }
        return l / bklen < oth.l / bklen;
    }
};
Quest qst[100005];
void discrete() // 离散化
{
    sort(all + 1, all + 1 + n);
    numsz = unique(all + 1, all + 1 + n) - (all + 1);
    for (int i = 1; i <= n; i++)
    {
        x[i] = lower_bound(all + 1, all + 1 + numsz, x[i]) - all;
    }
}
void makeAns(int cur)
{
    memset(ts, 0, sizeof(ts));
    int l = min(cur * bklen, n + 1), r = min(cur * bklen - 1, n);
    long long ansr = 0, ansnow = 0;
    while (qst[now].l / bklen + 1 == cur)
    {
        ansnow = ansr;
        while (r < qst[now].r)
        {
            r++;
            ts[x[r]]++;
            ansnow = max(ansnow, ts[x[r]] * all[x[r]]);
        }
        while (r > qst[now].r)
        {
            ts[x[r]]--;
            r--;
        }
        ansr = ansnow;
        while (l > qst[now].l)
        {
            l--;
            ts[x[l]]++;
            ansnow = max(ansnow, ts[x[l]] * all[x[l]]);
        }
        while (l < min(cur * bklen, n + 1)) // 回滚l
        {
            ts[x[l]]--;
            l++;
        }
        ans[qst[now].id] = ansnow;
        now++;
    }
}

int main()
{
    n = read(), q = read();
    bklen = sqrt(n);
    bksz = n / bklen + 1;
    for (int i = 1; i <= n; i++)
    {
        all[i] = x[i] = read();
    }
    discrete();
    for (int i = 1; i <= q; i++)
    {
        qst[i].l = read(), qst[i].r = read();
        qst[i].id = i;
    }
    sort(qst + 1, qst + 1 + q);
    for (int i = 1; i <= bksz; i++) // 逐一枚举每个块
    {
        makeAns(i);
    }
    for (int i = 1; i <= q; i++)
    {
        printf("%lld\n", ans[i]);
    }
    return 0;
}
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
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
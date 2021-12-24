#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define MX 200005
int read();
int ans[MX], a[MX], ls[MX], back[MX], st[MX], ed[MX];
struct Quest
{
    int id, l, r, lb, rb;
    bool operator<(const Quest oth) const
    {
        return (lb != oth.lb) ? lb < oth.lb : r < oth.r;
    }
};
Quest qst[MX];
int main()
{
    // 输入序列
    int n = read();
    int lens = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        ls[i] = a[i] = read();
    }
    // 离散化
    sort(ls + 1, ls + 1 + n);
    int nls = unique(ls + 1, ls + 1 + n) - (ls + 1);
    for (int i = 1; i <= n; i++)
    {
        a[i] = lower_bound(ls + 1, ls + 1 + nls, a[i]) - ls;
    }
    // 离线询问
    int m = read();
    for (int i = 1; i <= m; i++)
    {
        qst[i].l = read(), qst[i].r = read();
        qst[i].lb = qst[i].l / lens + 1;
        qst[i].rb = qst[i].r / lens + 1;
        qst[i].id = i;
    }
    sort(qst + 1, qst + 1 + m);
    // 回滚莫队
    int now = 1;
    for (int i = qst[1].lb; i <= qst[m].lb; i++) // 枚举每个块 处理所有左边界在该快内的询问
    {
        int l = min(n + 1, i * lens);
        int r = l - 1;
        int ansr = 0, ansl = 0, cnt = 0;
        while (qst[now].lb == i && now <= m) // 回滚莫队
        {
            if (qst[now].rb == i) // 左右边界都在该块内 暴力求解
            {
                ansl = 0;
                for (int p = qst[now].l; p <= qst[now].r; p++)
                {
                    if (st[a[p]] == 0)
                    {
                        st[a[p]] = p;
                    }
                    ansl = max(ansl, p - st[a[p]]);
                }
                for (int p = qst[now].l; p <= qst[now].r; p++)
                {
                    st[a[p]] = 0;
                }
                ans[qst[now].id] = ansl;
                now++;
                continue;
            }
            while (r < qst[now].r) // 滚动r
            {
                r++;
                if (st[a[r]] == 0)
                {
                    st[a[r]] = r;
                    back[++cnt] = a[r];
                }
                ed[a[r]] = r;
                ansr = max(ansr, r - st[a[r]]);
            }
            ansl = ansr;
            while (l > qst[now].l) // 滚动l
            {
                l--;
                if (ed[a[l]] == 0)
                {
                    ed[a[l]] = l;
                }
                ansl = max(ansl, ed[a[l]] - l);
            }
            ans[qst[now].id] = ansl;
            now++;
            while (l != i * lens) // 回滚l
            {
                if (ed[a[l]] == l)
                {
                    ed[a[l]] = 0;
                }
                l++;
            }
        }
        for (int i = 1; i <= cnt; i++) // 回滚r
        {
            st[back[i]] = ed[back[i]] = 0;
        }
    }
    // 输出
    for (int i = 1; i <= m; i++)
    {
        printf("%d\n", ans[i]);
    }
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
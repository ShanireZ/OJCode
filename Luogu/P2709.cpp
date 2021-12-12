#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int read();
int n, m, k, bklen, bksz;
int nums[50005], ts[50005], ans[50005];
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
Quest qst[50005];
void makeAns()
{
    int l = 1, r = 0, now = 0;
    for (int i = 1; i <= m; i++)
    {
        while (r < qst[i].r)
        {
            r++;
            now = now - ts[nums[r]] * ts[nums[r]] + (ts[nums[r]] + 1) * (ts[nums[r]] + 1);
            ts[nums[r]]++;
        }
        while (r > qst[i].r)
        {
            now = now - ts[nums[r]] * ts[nums[r]] + (ts[nums[r]] - 1) * (ts[nums[r]] - 1);
            ts[nums[r]]--;
            r--;
        }
        while (l < qst[i].l)
        {
            now = now - ts[nums[l]] * ts[nums[l]] + (ts[nums[l]] - 1) * (ts[nums[l]] - 1);
            ts[nums[l]]--;
            l++;
        }
        while (l > qst[i].l)
        {
            l--;
            now = now - ts[nums[l]] * ts[nums[l]] + (ts[nums[l]] + 1) * (ts[nums[l]] + 1);
            ts[nums[l]]++;
        }
        ans[qst[i].id] = now;
    }
}
int main()
{
    n = read(), m = read(), k = read();
    bklen = sqrt(n);
    bksz = n / bklen + 1;
    for (int i = 1; i <= n; i++)
    {
        nums[i] = read();
    }
    for (int i = 1; i <= m; i++)
    {
        qst[i].l = read(), qst[i].r = read();
        qst[i].id = i;
    }
    sort(qst + 1, qst + 1 + m);
    makeAns();
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
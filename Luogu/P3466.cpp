#include <algorithm>
#include <iostream>
using namespace std;
#define MX 100005
int n, k, pos, t[MX], h[MX], all[MX], read();
long long toth[MX];
int lowbit(int x)
{
    return x & (-x);
}
void edit(int x, int opt)
{
    int val = all[x];
    while (x <= pos)
    {
        toth[x] += val * opt, t[x] += opt;
        x += lowbit(x);
    }
}
pair<int, long long> query(int x)
{
    pair<int, long long> ans = make_pair(0, 0);
    while (x)
    {
        ans.first += t[x], ans.second += toth[x];
        x -= lowbit(x);
    }
    return ans;
}
int main()
{
    n = read(), k = read();
    for (int i = 1; i <= n; i++)
    {
        all[i] = h[i] = read();
    }
    sort(all + 1, all + 1 + n);
    pos = unique(all + 1, all + 1 + n) - (all + 1);
    for (int i = 1; i <= n; i++)
    {
        h[i] = lower_bound(all + 1, all + 1 + pos, h[i]) - all;
    }
    for (int i = 1; i < k; i++)
    {
        edit(h[i], 1);
    }
    long long mint = 0x3f3f3f3f3f3f3f3f, ast = 1, iso = h[1];
    for (int i = k, st = 1; i <= n; i++, st++)
    {
        edit(h[i], 1); // 加入當前數
        int l = 1, r = pos;
        while (l <= r) // l為中位數
        {
            int mid = (l + r) / 2;
            (query(mid).first >= (k + 1) / 2) ? (r = mid - 1) : (l = mid + 1);
        }
        pair<int, long long> qmax = query(pos), ql = query(l);
        long long cnt = qmax.second - ql.second * 2 - all[l] * qmax.first + 2 * all[l] * ql.first;
        if (cnt < mint)
        {
            mint = cnt, ast = st, iso = l;
        }
        edit(h[st], -1); // 刪除最前數
    }
    printf("%lld\n", mint);
    for (int i = 1; i <= n; i++)
    {
        printf("%d\n", (i >= ast && i < ast + k) ? all[iso] : all[h[i]]);
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
// TAG: 離散化 中位數 樹狀陣列 線段樹 分段統計 同P2263
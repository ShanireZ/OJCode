#include <algorithm>
#include <cmath>
#include <ctime>
#include <iostream>
#include <random>
using namespace std;
struct Node
{
    int l, r, k, id;
};
Node ns[300005];
int a[300005], cnt[300005], k[300005], ans[300005];
bool cmp(Node x, Node y)
{
    if (k[x.l] == k[y.l])
    {
        return x.r < y.r;
    }
    return x.l < y.l;
}
void check(Node x)
{
    mt19937 rnd;
    rnd.seed(time(0));
    int mod = x.r - x.l + 1, ex = x.l, res = 1e9;
    for (int i = 1; i <= 100; i++)
    {
        int now = rnd() % mod + ex;
        if (cnt[a[now]] > mod / x.k)
        {
            res = min(res, a[now]);
        }
    }
    ans[x.id] = (res == 1e9 ? -1 : res);
}
int main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    int sz = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        k[i] = (i - 1) / sz + 1;
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> ns[i].l >> ns[i].r >> ns[i].k;
        ns[i].id = i;
    }
    sort(ns + 1, ns + q + 1, cmp);
    int l = 1, r = 0;
    for (int i = 1; i <= q; i++)
    {
        while (r < ns[i].r)
        {
            r++;
            cnt[a[r]]++;
        }
        while (r > ns[i].r)
        {
            cnt[a[r]]--;
            r--;
        }
        while (l < ns[i].l)
        {
            cnt[a[l]]--;
            l++;
        }
        while (l > ns[i].l)
        {
            l--;
            cnt[a[l]]++;
        }
        check(ns[i]);
    }
    for (int i = 1; i <= q; i++)
    {
        cout << ans[i] << '\n';
    }
    return 0;
}
// TAG: 莫队 随机答案
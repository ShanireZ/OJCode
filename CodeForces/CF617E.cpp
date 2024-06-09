#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
struct Node
{
    int l, r, id;
};
Node ns[100005];
int cnt[1100000], qz[100005], sz, n, m, k;
long long res, ans[100005];
bool cmp(Node a, Node b)
{
    if (a.l / sz == b.l / sz)
    {
        return a.r < b.r;
    }
    return a.l < b.l;
}
int main()
{
    cin >> n >> m >> k;
    sz = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> qz[i];
        qz[i] ^= qz[i - 1];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> ns[i].l >> ns[i].r;
        ns[i].id = i;
    }
    sort(ns + 1, ns + m + 1, cmp);
    int st = 1, ed = 0;
    cnt[0] = 1;
    for (int i = 1; i <= m; i++)
    {
        while (ed < ns[i].r)
        {
            ed++;
            res += cnt[qz[ed] ^ k];
            cnt[qz[ed]]++;
        }
        while (ed > ns[i].r)
        {
            cnt[qz[ed]]--;
            res -= cnt[qz[ed] ^ k];
            ed--;
        }
        while (st < ns[i].l)
        {
            cnt[qz[st - 1]]--;
            res -= cnt[qz[st - 1] ^ k];
            st++;
        }
        while (st > ns[i].l)
        {
            st--;
            res += cnt[qz[st - 1] ^ k];
            cnt[qz[st - 1]]++;
        }
        ans[ns[i].id] = res;
    }
    for (int i = 1; i <= m; i++)
    {
        cout << ans[i] << '\n';
    }
    return 0;
}
// TAG: 莫队 分块 异或和
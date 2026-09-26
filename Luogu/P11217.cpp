#include <algorithm>
#include <iostream>
using namespace std;
long long n, q, w, tot, td[200005], ti1d[200005];
void edit(int x, long long v)
{
    int p = x;
    while (x <= n)
    {
        td[x] += v;
        ti1d[x] += (p - 1) * v;
        x += (x & -x);
    }
}
long long query(int x)
{
    int p = x;
    long long res = 0;
    while (x > 0)
    {
        res += td[x] * p - ti1d[x];
        x -= (x & -x);
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> q >> w;
    for (int i = 1, pre = 0, now = 0; i <= n; i++)
    {
        cin >> now;
        edit(i, now - pre);
        pre = now, tot += now;
    }
    while (q--)
    {
        long long l, r, d;
        cin >> l >> r >> d;
        edit(l, d), edit(r + 1, -d);
        tot += (r - l + 1) * d;
        long long ans = 0, rm = w, now = tot;
        while (rm > now)
        {
            ans++, rm -= now;
            now *= 2;
        }
        int lp = 1, rp = n;
        while (lp <= rp)
        {
            int mid = (lp + rp) / 2;
            if (query(mid) * (1ll << ans) < rm)
            {
                lp = mid + 1;
            }
            else
            {
                rp = mid - 1;
            }
        }
        cout << ans * n + rp << "\n";
    }
    return 0;
}
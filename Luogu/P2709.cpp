#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
long long n, m, k, ans, a[50005], p[50005], cnt[50005], res[50005];
struct Node
{
    int l, r, id;
    bool operator<(const Node &oth) const
    {
        if (p[l] == p[oth.l])
        {
            return p[l] % 2 ? r < oth.r : r > oth.r;
        }
        return p[l] < p[oth.l];
    }
};
Node q[50005];
int main()
{
    cin >> n >> m >> k;
    int sz = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        p[i] = (i - 1) / sz + 1;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    sort(q + 1, q + m + 1);
    for (int i = 1, l = 1, r = 0; i <= m; i++)
    {
        while (r < q[i].r) //! r向右
        {
            r++;
            ans -= cnt[a[r]] * cnt[a[r]];
            cnt[a[r]]++;
            ans += cnt[a[r]] * cnt[a[r]];
        }
        while (l > q[i].l) //! l向左
        {
            l--;
            ans -= cnt[a[l]] * cnt[a[l]];
            cnt[a[l]]++;
            ans += cnt[a[l]] * cnt[a[l]];
        }
        while (r > q[i].r) //! r向左
        {
            ans -= cnt[a[r]] * cnt[a[r]];
            cnt[a[r]]--;
            ans += cnt[a[r]] * cnt[a[r]];
            r--;
        }
        while (l < q[i].l) //! l向右
        {
            ans -= cnt[a[l]] * cnt[a[l]];
            cnt[a[l]]--;
            ans += cnt[a[l]] * cnt[a[l]];
            l++;
        }
        res[q[i].id] = ans;
    }
    for (int i = 1; i <= m; i++)
    {
        cout << res[i] << endl;
    }
    return 0;
}
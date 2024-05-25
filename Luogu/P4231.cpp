#include <algorithm>
#include <iostream>
using namespace std;
long long cd[10000007], a[10000007], n, m, ans1, ans2;
int lowbit(int x)
{
    return x & -x;
}
void edit(int x, long long k)
{
    while (x <= n)
    {
        cd[x] += k;
        x += lowbit(x);
    }
}
long long query(int x)
{
    long long ans = 0;
    while (x)
    {
        ans += cd[x];
        x -= lowbit(x);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        long long l, r, s, e;
        cin >> l >> r >> s >> e;
        long long delta = (e - s) / (r - l);
        // 差分d: [l] +s   [l + 1]~[r] +delta    [r+1] -e
        // cd为差分d的差分
        edit(l, s), edit(l + 1, -s);
        edit(l + 1, delta), edit(r + 1, -delta);
        edit(r + 1, -e), edit(r + 2, e);
    }
    for (int i = 1; i <= n; i++)
    {
        a[i] = query(i) + a[i - 1];
        ans1 = ans1 ^ a[i];
        ans2 = max(ans2, a[i]);
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}
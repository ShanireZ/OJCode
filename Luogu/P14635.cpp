#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
long long n, m, mn = 2e18, x[100005], y[100005], pre[100005];
bool check(long long k)
{
    for (__int128 solo = k % 2, ps = k / 2; solo <= min(n, k); solo += 2, ps--)
    {
        if (ps * mn + pre[solo] <= m)
        {
            return true;
        }
    }
    return false;
};
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x[i] >> y[i];
        mn = min(mn, x[i] + y[i]);
    }
    sort(x + 1, x + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        pre[i] = pre[i - 1] + x[i];
    }
    long long l = 0, r = m;
    while (l <= r)
    {
        long long mid = (l + r) / 2;
        check(mid) ? l = mid + 1 : r = mid - 1;
    }
    cout << r << endl;
    return 0;
}
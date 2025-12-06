#include <algorithm>
#include <iostream>
using namespace std;
long long n, m, ans, mn = 2e18, x[100005], y;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x[i] >> y;
        mn = min(mn, x[i] + y);
    }
    sort(x + 1, x + n + 1);
    for (int i = 0; i <= n && m >= x[i]; i++)
    {
        m -= x[i];
        ans = max(ans, i + m / mn * 2);
    }
    cout << ans << endl;
    return 0;
}
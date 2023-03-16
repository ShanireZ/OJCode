#include <iostream>
using namespace std;
int main()
{
    long long n, t, now = 1, ans = 0;
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        long long d, b;
        cin >> d >> b;
        now = max(now, d);
        long long x = min(b, t - now + 1);
        ans += x, now += x;
        if (now > t)
        {
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}
// TAG: 模拟 贪心 USACO 23FEB Bronze
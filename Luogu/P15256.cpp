#include <algorithm>
#include <iostream>
using namespace std;
long long a[100005], n, q;
int main()
{
    cin >> n >> q;
    fill(a, a + 100005, 2e18);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= 100000; i++)
    {
        a[i] = min(a[i], a[i - 1] * 2);
    }
    for (int i = 100000; i >= 1; i--)
    {
        a[i] = min(a[i], a[i + 1]);
    }
    while (q--)
    {
        long long x, ans = 0, now = 1;
        cin >> x;
        while (x)
        {
            if (x % 2)
            {
                ans += a[now];
            }
            x /= 2, now++;
            ans = min(ans, a[now]); // 可以选一个大包覆盖之前的所有小包
        }
        cout << ans << endl;
    }
    return 0;
}
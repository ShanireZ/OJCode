#include <algorithm>
#include <iostream>
using namespace std;
long long a[200005], n, x, y;
int main()
{
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    long long ans = a[1], now = a[1];
    for (int i = 1; i < n; i++)
    {
        if (x * (a[i + 1] - a[i]) % (y - x) != 0)
        {
            cout << -1 << endl;
            return 0;
        }
        now -= x * (a[i + 1] - a[i]) / (y - x);
        if (now >= 0)
        {
            ans += now;
        }
        else
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}
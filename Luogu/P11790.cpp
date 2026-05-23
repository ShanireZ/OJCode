#include <algorithm>
#include <iostream>
using namespace std;
long long n, q, s, t, ans, d[200005], a[200005];
int main()
{
    cin >> n >> q >> s >> t >> a[0];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        d[i] = a[i] - a[i - 1];
        d[i] < 0 ? (ans -= d[i] * t) : (ans -= d[i] * s);
    }
    while (q--)
    {
        long long l, r, x;
        cin >> l >> r >> x;
        d[l] < 0 ? (ans += d[l] * t) : (ans += d[l] * s);
        d[l] += x;
        d[l] < 0 ? (ans -= d[l] * t) : (ans -= d[l] * s);
        if (r + 1 <= n)
        {
            d[r + 1] < 0 ? (ans += d[r + 1] * t) : (ans += d[r + 1] * s);
            d[r + 1] -= x;
            d[r + 1] < 0 ? (ans -= d[r + 1] * t) : (ans -= d[r + 1] * s);
        }
        cout << ans << endl;
    }
    return 0;
}
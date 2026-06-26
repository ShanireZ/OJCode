#include <algorithm>
#include <iostream>
using namespace std;
int c, T, n, m;
long long a[100005], b[100005];
int main()
{

    cin >> c >> T;
    while (T--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= m; i++)
        {
            cin >> b[i];
        }
        sort(a + 1, a + n + 1);
        sort(b + 1, b + m + 1);
        long long ans = 0;
        if (b[1] <= a[1])
        {
            ans += a[1] - b[1];
        }
        if (b[m] >= a[n])
        {
            ans += b[m] - a[n];
        }
        for (int i = 1; i < n; i++)
        {
            int l = upper_bound(b + 1, b + m + 1, a[i]) - b;
            int r = lower_bound(b + 1, b + m + 1, a[i + 1]) - b - 1;
            if (l <= r)
            {
                long long res = min(b[r] - a[i], a[i + 1] - b[l]);
                for (int j = l; j < r; j++)
                {
                    res = min(res, (a[i + 1] - a[i]) - (b[j + 1] - b[j]));
                }
                ans += res;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
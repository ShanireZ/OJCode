#include <algorithm>
#include <iostream>
using namespace std;
long long T, n, a[200005], sum[200005];
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++)
        {
            sum[i] = sum[i - 1] + a[i];
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += a[i] * 2 * (i - 1);
            ans += (sum[n] - sum[i]) * 2;
        }
        cout << ans << endl;
    }
    return 0;
}
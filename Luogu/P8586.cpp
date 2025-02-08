#include <algorithm>
#include <iostream>
using namespace std;
long long n, k, d, m, ans, day[300005];
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> d >> m;
        day[d] += m;
    }
    for (int i = 0; i <= 300001; i++)
    {
        long long x = k;
        if (i > 0)
        {
            x -= min(x, day[i - 1]);
        }
        long long t = min(x, day[i]);
        x -= t, day[i] -= t;
        ans += k - x;
    }
    cout << ans << endl;
    return 0;
}
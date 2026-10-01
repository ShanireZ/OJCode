#include <algorithm>
#include <iostream>
using namespace std;
#define MX 100005
long long n, m, a[505], b[505], dp[MX]; // dp[x]:x张优惠券最多换多少糖果
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
    }
    for (int t = 1; t <= m; t++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i] <= t)
            {
                int nt = t - a[i] + b[i];
                dp[t] = max(dp[t], b[i] + dp[nt]);
            }
        }
    }
    for (int i = 1, x = 0; i <= m; i++)
    {
        while (x + dp[x] < i)
        {
            x++;
        }
        cout << x << endl;
    }
    return 0;
}
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
long long mindp[2005], a[2005], b[2005], ans = 1e18, dp;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    mindp[0] = 1e18, sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            long long dp = mindp[j] + abs(a[i] - b[j]);
            mindp[j] = min(mindp[j - 1], dp);
        }
    }
    ans = min(ans, mindp[n]);
    memset(mindp, 0, sizeof(mindp));
    mindp[0] = 1e18, sort(b + 1, b + n + 1, greater<long long>());
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            long long dp = mindp[j] + abs(a[i] - b[j]);
            mindp[j] = min(mindp[j - 1], dp);
        }
    }
    ans = min(ans, mindp[n]);
    cout << ans << endl;
    return 0;
}
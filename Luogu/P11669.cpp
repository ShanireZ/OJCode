#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int n, a[7505], b[7505], ans[7505], dp[7505][7505];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        dp[0][0] += (a[i] == b[i]);
    }
    for (int x = 1; x <= n; x++)
    {
        dp[x][x] = dp[0][0];
        ans[dp[x][x]]++;
    }
    for (int len = 3; len <= n; len += 2)
    {
        for (int x = 1, y = len; y <= n; x++, y++)
        {
            int ex = (a[x] == b[y]) + (a[y] == b[x]);
            ex -= (a[x] == b[x]) + (a[y] == b[y]);
            dp[x][y] = dp[x + 1][y - 1] + ex;
            ans[dp[x][y]]++;
        }
    }
    for (int x = 1, y = 2; y <= n; x++, y++)
    {
        int ex = (a[x] == b[y]) + (a[y] == b[x]);
        ex -= (a[x] == b[x]) + (a[y] == b[y]);
        dp[x][y] = dp[0][0] + ex;
        ans[dp[x][y]]++;
    }
    for (int len = 4; len <= n; len += 2)
    {
        for (int x = 1, y = len; y <= n; x++, y++)
        {
            int ex = (a[x] == b[y]) + (a[y] == b[x]);
            ex -= (a[x] == b[x]) + (a[y] == b[y]);
            dp[x][y] = dp[x + 1][y - 1] + ex;
            ans[dp[x][y]]++;
        }
    }
    for (int i = 0; i <= n; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}
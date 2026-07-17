#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int n, m, a[150005], dp[400][400];
int main()
{
    cin >> n >> m;
    int mx = pow(n, 0.5);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        for (int x = 1; x <= mx; x++)
        {
            dp[x][i % x] += a[i];
        }
    }
    while (m--)
    {
        char cmd;
        int x, y;
        cin >> cmd >> x >> y;
        if (cmd == 'A')
        {
            if (x <= mx)
            {
                cout << dp[x][y] << endl;
            }
            else
            {
                int ans = 0;
                for (int i = y; i <= n; i += x)
                {
                    ans += a[i];
                }
                cout << ans << endl;
            }
        }
        else
        {
            int delta = y - a[x];
            for (int i = 1; i <= mx; i++)
            {
                dp[i][x % i] += delta;
            }
            a[x] = y;
        }
    }
    return 0;
}
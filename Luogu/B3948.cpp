#include <algorithm>
#include <iostream>
using namespace std;
int n, res[1005][5], now[1005][5];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            cin >> res[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            cin >> now[i][j];
        }
    }
    for (int t = 0; t < n; t++)
    {
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int ni = (i + t > n ? i + t - n : i + t), ok = 6, cnt = 0;
            for (int j = 1; j <= 4; j++)
            {
                cnt += now[i][j];
                if (res[ni][j] == 1 && now[i][j] == 0)
                {
                    ok = 3;
                }
                else if (res[ni][j] == 0 && now[i][j] == 1)
                {
                    ok = 0;
                    break;
                }
            }
            if (ok == 6 || (ok == 3 && cnt))
            {
                ans += ok;
            }
        }
        cout << ans << " ";
    }
    return 0;
}
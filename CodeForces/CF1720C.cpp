#include <iostream>
using namespace std;
int a[505][505];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, ans = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                char ch;
                cin >> ch;
                a[i][j] = ch - '0';
                ans += a[i][j];
            }
        }
        int cnt = 4, all0 = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                int now = a[i][j] + a[i][j + 1] + a[i + 1][j + 1] + a[i + 1][j];
                if (now)
                {
                    cnt = min(cnt, now), all0 = 0;
                }
            }
        }
        if (all0 == 1)
        {
            cout << 0 << endl;
        }
        else
        {
            ans = (cnt <= 2) ? ans : ans - cnt + 2;
            cout << ans << endl;
        }
    }
    return 0;
}
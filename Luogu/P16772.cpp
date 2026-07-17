#include <algorithm>
#include <iostream>
using namespace std;
int T, n, c[1005][1005];
int main()
{
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> c[i][j];
            }
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            long long res = 0;
            int x = i, y = 1;
            while (x <= n && y <= n)
            {
                res += c[x][y];
                x++, y++;
            }
            ans = max(ans, res);
            res = 0, x = 1, y = i;
            while (x <= n && y <= n)
            {
                res += c[x][y];
                x++, y++;
            }
            ans = max(ans, res);
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
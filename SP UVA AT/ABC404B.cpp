#include <algorithm>
#include <iostream>
using namespace std;
int n, ans;
char s[105][105][4], t[105][105];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> s[i][j][0];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> t[i][j];
            ans += (t[i][j] != s[i][j][0]);
        }
    }
    for (int tz = 1; tz < 4; tz++)
    {
        int res = tz;
        for (int i = 1, y = n - i + 1; i <= n; i++, y--)
        {
            for (int j = 1, x = 1; j <= n; j++, x++)
            {
                s[x][y][tz] = s[i][j][tz - 1];
                res += (s[x][y][tz] != t[x][y]);
            }
        }
        ans = min(ans, res);
    }
    cout << ans << endl;
    return 0;
}
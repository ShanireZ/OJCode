#include <algorithm>
#include <iostream>
using namespace std;
int n, m, ans, a[15][15], l[15][15], r[15][15], up[15][15];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j])
            {
                l[i][j] = l[i][j - 1] + 1;
                up[i][j] = up[i - 1][j] + 1;
            }
        }
        for (int j = m; j >= 1; j--)
        {
            if (a[i][j])
            {
                r[i][j] = r[i][j + 1] + 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1][j])
            {
                l[i][j] = min(l[i][j], l[i - 1][j]);
                r[i][j] = min(r[i][j], r[i - 1][j]);
            }
            ans = max(ans, (l[i][j] + r[i][j] - 1) * up[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
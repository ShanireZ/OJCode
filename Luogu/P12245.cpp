#include <algorithm>
#include <iostream>
using namespace std;
int a[505][505], mx[505], n, m, ans;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                continue;
            }
            int c = 0;
            for (int k = 1; k <= m; k++)
            {
                c += (a[i][k] && a[j][k]);
            }
            mx[i] = max(mx[i], c);
        }
    }
    for (int k = 1; k <= m; k++)
    {
        int pre = a[1][k], res = 0;
        a[1][k] = 1;
        for (int i = 2; i <= n; i++)
        {
            int c1 = 0;
            for (int j = 1; j <= m; j++)
            {
                c1 += (a[1][j] && a[i][j]);
            }
            res += (c1 >= mx[i]);
        }
        ans = max(ans, res), a[1][k] = pre;
    }
    cout << ans << endl;
    return 0;
}
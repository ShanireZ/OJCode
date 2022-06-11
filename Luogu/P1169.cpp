#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int mp[2005][2005], l[2005][2005], r[2005][2005], up[2005][2005], ans1, ans2;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mp[i][j];
            l[i][j] = r[i][j] = up[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 2; j <= m; j++)
        {
            if (mp[i][j] != mp[i][j - 1])
            {
                l[i][j] += l[i][j - 1];
            }
        }
        for (int j = m - 1; j >= 1; j--)
        {
            if (mp[i][j] != mp[i][j + 1])
            {
                r[i][j] += r[i][j + 1];
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (mp[i][j] != mp[i - 1][j])
            {
                up[i][j] += up[i - 1][j];
                l[i][j] = min(l[i][j], l[i - 1][j]);
                r[i][j] = min(r[i][j], r[i - 1][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int a = l[i][j] + r[i][j] - 1, b = up[i][j];
            ans1 = max(ans1, min(a, b) * min(a, b));
            ans2 = max(ans2, a * b);
        }
    }
    cout << ans1 << endl;
    cout << ans2 << endl;
    return 0;
}
#include <iostream>
using namespace std;
int l[1005][1005], r[1005][1005], up[1005][1005], mp[1005][1005];
int main()
{
    int n, m, ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char ch;
            cin >> ch;
            if (ch == 'F')
            {
                mp[i][j] = r[i][j] = 1;
                l[i][j] = l[i][j - 1] + 1, up[i][j] = up[i - 1][j] + 1;
            }
        }
        for (int j = m; j >= 1; j--)
        {
            if (mp[i][j] == 1)
            {
                r[i][j] += r[i][j + 1];
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (up[i][j] > 1)
            {
                l[i][j] = min(l[i][j], l[i - 1][j]);
                r[i][j] = min(r[i][j], r[i - 1][j]);
            }
            int a = l[i][j] + r[i][j] - 1, b = up[i][j];
            ans = max(ans, a * b);
        }
    }
    cout << ans * 3 << endl;
    return 0;
}
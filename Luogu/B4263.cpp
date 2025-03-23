#include <algorithm>
#include <iostream>
using namespace std;
int a[1005][1005], n, m, res, ex;
bool check(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m || a[x][y] || a[x - 1][y] || a[x + 1][y] || a[x][y - 1] || a[x][y + 1])
    {
        return false;
    }
    return true;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char ch;
            cin >> ch;
            a[i][j] = (ch == '.' ? 0 : 1); // 1障碍 0空地
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            res += check(i, j);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == 1)
            {
                a[i][j] = 0;
                int cnt = check(i, j) + check(i - 1, j) + check(i + 1, j) + check(i, j - 1) + check(i, j + 1);
                a[i][j] = 1, ex = max(ex, cnt);
            }
        }
    }
    cout << res + ex << endl;
    return 0;
}
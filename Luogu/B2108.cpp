#include <cmath>
#include <iostream>
using namespace std;
int a[105][105], ans[105][105], n, m;
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
    for (int i = 2; i < n; i++)
    {
        for (int j = 2; j < m; j++)
        {
            double x = (a[i][j] + a[i - 1][j] + a[i][j - 1] + a[i + 1][j] + a[i][j + 1]) / 5.0;
            ans[i][j] = round(x);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1 || j == 1 || i == n || j == m)
            {
                ans[i][j] = a[i][j];
            }
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
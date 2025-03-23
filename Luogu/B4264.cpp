#include <algorithm>
#include <iostream>
using namespace std;
int a[505][505], n, m, ans;
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
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (a[i][j] * a[i + 1][j + 1] == a[i + 1][j] * a[i][j + 1])
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
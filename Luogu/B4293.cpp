#include <algorithm>
#include <iostream>
using namespace std;
int a[105][105], qz[105][105], n, m, ans;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            qz[i][j] = qz[i - 1][j] + qz[i][j - 1] - qz[i - 1][j - 1] + a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) // 左上
        {
            for (int k = 0; i + k <= n && j + k <= m && a[i + k][j + k]; k++) // 右下
            {
                if (qz[i + k][j + k] - qz[i + k][j - 1] - qz[i - 1][j + k] + qz[i - 1][j - 1] == k + 1)
                {
                    ans = max(ans, k + 1);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) // 右上
        {
            for (int k = 0; i + k <= n && j - k >= 1 && a[i + k][j - k]; k++) // 左下
            {
                if (qz[i + k][j] - qz[i + k][j - k - 1] - qz[i - 1][j] + qz[i - 1][j - k - 1] == k + 1)
                {
                    ans = max(ans, k + 1);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
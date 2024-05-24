#include <algorithm>
#include <iostream>
using namespace std;
int a[2005][2005];
int main()
{
    int n, ans = -1e9;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= n; j++)
        {
            sum += a[i][j];
        }
        ans = max(ans, sum);
    }
    for (int j = 1; j <= n; j++)
    {
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += a[i][j];
        }
        ans = max(ans, sum);
    }
    for (int x = 1; x < n * 2; x++)
    {
        int i = max(1, x - n + 1), j = min(n, x), sum = 0;
        while (i <= n && j >= 1)
        {
            sum += a[i][j];
            i++, j--;
        }
        ans = max(ans, sum);
    }
    for (int x = 1; x < n * 2; x++)
    {
        int i = max(1, x - n + 1), j = max(1, n - x + 1), sum = 0;
        while (i <= n && j <= n)
        {
            sum += a[i][j];
            i++, j++;
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
#include <algorithm>
#include <iostream>
#include <numeric>
using namespace std;
int a[1005][1005], m, n, h, ans;
int main()
{
    cin >> m >> n >> h;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 2; i < m; i++)
    {
        for (int j = 2; j < n; j++)
        {
            int all[9] = {a[i][j], a[i - 1][j], a[i + 1][j], a[i][j - 1], a[i][j + 1], a[i - 1][j - 1], a[i - 1][j + 1], a[i + 1][j - 1], a[i + 1][j + 1]};
            sort(all, all + 9);
            if (all[8] - all[0] <= h)
            {
                ans = max(ans, accumulate(all, all + 9, 0));
            }
        }
    }
    cout << ans << endl;
    return 0;
}
#include <algorithm>
#include <iostream>
using namespace std;
int d[5][1000005], a[5][1000005];
int main()
{
    int n, m, ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int l, r, k;
        cin >> l >> r >> k;
        d[k][l]++, d[k][r + 1]--;
    }
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = d[i][j] + a[i][j - 1];
        }
    }
    for (int j = 1; j <= n; j++)
    {
        if (a[1][j] && a[2][j] && a[3][j] == 0)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
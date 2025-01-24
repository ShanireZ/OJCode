#include <algorithm>
#include <iostream>
using namespace std;
int a[55][55], sum[55], n, m, l;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            sum[j] += a[i][j];
        }
    }
    for (int j = 1; j <= m; j++)
    {
        if (sum[j] >= sum[l])
        {
            l = j;
        }
    }
    int ans = 0, cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (ans < a[i][l])
        {
            cnt = 1, ans = a[i][l];
        }
        else if (ans == a[i][l])
        {
            cnt++;
        }
    }
    cout << ans << " " << cnt << endl;
    return 0;
}
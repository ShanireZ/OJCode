#include <iostream>
#include <algorithm>
using namespace std;
int a[505][505];
int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            cin >> a[i][j];
            a[j][i] = a[i][j];
        }
        sort(a[i] + 1, a[i] + 1 + n);
        ans = max(ans, a[i][n - 1]);
    }
    cout << 1 << endl
         << ans;
    return 0;
}
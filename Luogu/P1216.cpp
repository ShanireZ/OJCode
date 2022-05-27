#include <algorithm>
#include <iostream>
using namespace std;
int m[1005][1005], tot[1005][1005];
int main()
{
    int r;
    cin >> r;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> m[i][j];
            tot[i][j] = m[i][j] + max(tot[i - 1][j - 1], tot[i - 1][j]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= r; i++)
    {
        ans = max(ans, tot[r][i]);
    }
    cout << ans;
    return 0;
}
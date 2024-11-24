#include <algorithm>
#include <iostream>
using namespace std;
int n, k, ans, a[1005][1005], d[1005][1005];
int main()
{
    cin >> n >> k;
    while (n--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1++, y1++;
        d[x1][y1]++, d[x1][y2 + 1]--;
        d[x2 + 1][y1]--, d[x2 + 1][y2 + 1]++;
    }
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 1; j <= 1000; j++)
        {
            a[i][j] = d[i][j] - a[i - 1][j - 1] + a[i - 1][j] + a[i][j - 1];
        }
    }
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 1; j <= 1000; j++)
        {
            ans += (a[i][j] == k);
        }
    }
    cout << ans << endl;
    return 0;
}
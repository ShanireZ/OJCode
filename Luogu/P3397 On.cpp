#include <algorithm>
#include <iostream>
using namespace std;
int d[1005][1005], a[1005][1005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int x = x1; x <= x2; x++)
        {
            d[x][y1]++, d[x][y2 + 1]--;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = d[i][j] + a[i][j - 1];
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
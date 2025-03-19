#include <algorithm>
#include <iostream>
using namespace std;
int a[1005][1005], n, m, cnt, x, y;
int ms[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
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
    cin >> x >> y;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] != x)
            {
                continue;
            }
            for (int k = 0; k < 4; k++)
            {
                int ni = i + ms[k][0], nj = j + ms[k][1];
                if (ni < 1 || ni > n || nj < 1 || nj > m || a[ni][nj] != y)
                {
                    continue;
                }
                cnt++;
                break;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
#include <algorithm>
#include <iostream>
using namespace std;
int h[105][105], n, m, ans = 0;
int ms[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> h[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int ok = 1;
            for (int k = 0; k < 8; k++)
            {
                int ni = i + ms[k][0], nj = j + ms[k][1];
                if (ni >= 1 && ni <= n && nj >= 1 && nj <= m && h[ni][nj] < h[i][j])
                {
                    ok = 0;
                    break;
                }
            }
            ans += ok;
        }
    }
    cout << ans << endl;
    return 0;
}
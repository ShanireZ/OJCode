#include <algorithm>
#include <iostream>
using namespace std;
int qz[105][105], n, m, k, ans = 1e9;
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char c;
            cin >> c;
            qz[i][j] = qz[i - 1][j] + qz[i][j - 1] - qz[i - 1][j - 1] + c - '0';
        }
    }
    for (int x = 1; x <= n; x++) // 枚举左上
    {
        for (int y = 1; y <= m; y++)
        {
            for (int xx = x; xx <= n; xx++) // 枚举右下
            {
                for (int yy = y; yy <= m; yy++)
                {
                    int cnt = qz[xx][yy] - qz[x - 1][yy] - qz[xx][y - 1] + qz[x - 1][y - 1];
                    if (cnt >= k)
                    {
                        ans = min(ans, (xx - x + 1) * (yy - y + 1));
                    }
                }
            }
        }
    }
    cout << (ans == 1e9 ? 0 : ans) << endl;
    return 0;
}
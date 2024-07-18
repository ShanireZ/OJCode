#include <algorithm>
#include <iostream>
using namespace std;
char mp[15][15];
int main()
{
    int n, m, ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mp[i][j];
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
                    int t0 = 0, t1 = 0;
                    for (int i = x; i <= xx; i++) // 枚举每个格子
                    {
                        for (int j = y; j <= yy; j++)
                        {
                            mp[i][j] == '1' ? t1++ : t0++;
                        }
                    }
                    if (t0 == t1)
                    {
                        ans = max(ans, t0 + t1);
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
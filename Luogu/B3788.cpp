#include <algorithm>
#include <iostream>
using namespace std;
int mp1[55][55], mp2[55][55];
int main()
{
    int n1, m1, n2, m2;
    cin >> n1 >> m1;
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= m1; j++)
        {
            cin >> mp1[i][j];
        }
    }
    cin >> n2 >> m2;
    for (int i = 1; i <= n2; i++)
    {
        for (int j = 1; j <= m2; j++)
        {
            cin >> mp2[i][j];
        }
    }
    int ans = 0, ex = n2 - 1;
    for (int i = 1 - (n2 - 1); i <= n1; i++, ex--) // 枚举图形2左上角在坐标系中位置
    {
        int ey = m2 - 1;
        for (int j = 1 - (m2 - 1); j <= m1; j++, ey--)
        {
            int cnt = 0;
            for (int x = max(1, i); x <= min(n1, i + n2 - 1) && cnt != -1; x++)
            {
                for (int y = max(1, j); y <= min(m1, j + m2 - 1); y++)
                {
                    if (mp1[x][y] != mp2[x + ex][y + ey])
                    {
                        cnt = -1;
                        break;
                    }
                    cnt++;
                }
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans << "\n";
    return 0;
}
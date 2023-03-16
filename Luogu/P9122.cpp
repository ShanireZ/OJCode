#include <cstring>
#include <iostream>
using namespace std;
int cav[25][25], stp[10][25][25], tag[25][25], now[25][25];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(tag, 0, sizeof(tag));
        int n, k;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                char x;
                cin >> x;
                cav[i][j] = (x == '*');
            }
        }
        cin >> k;
        for (int i = 1; i <= k; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                char x;
                cin >> x;
                stp[1][i][j] = stp[2][j][k - i + 1] = (x == '*');
                stp[3][k - j + 1][i] = stp[4][k - i + 1][k - j + 1] = (x == '*');
            }
        }
        for (int x = 1; x <= 4; x++)
        {
            for (int ci = 1; ci + k - 1 <= n; ci++)
            {
                for (int cj = 1; cj + k - 1 <= n; cj++)
                {
                    int ok = 1;
                    for (int si = 1; si <= k && ok; si++)
                    {
                        for (int sj = 1; sj <= k; sj++)
                        {
                            if (cav[ci + si - 1][cj + sj - 1] == 0 && stp[x][si][sj] == 1)
                            {
                                ok = 0;
                                break;
                            }
                            else if (cav[ci + si - 1][cj + sj - 1] == 1 && stp[x][si][sj] == 1)
                            {
                                now[si][sj] = 1;
                            }
                            else
                            {
                                now[si][sj] = 0;
                            }
                        }
                    }
                    if (ok)
                    {
                        for (int si = 1; si <= k; si++)
                        {
                            for (int sj = 1; sj <= k; sj++)
                            {
                                tag[ci + si - 1][cj + sj - 1] += now[si][sj];
                            }
                        }
                    }
                }
            }
        }
        int ok = 1;
        for (int i = 1; i <= n && ok; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (cav[i][j] && tag[i][j] == 0)
                {
                    ok = 0;
                    break;
                }
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}
// TAG: 模拟 枚举 USACO 23FEB Bronze
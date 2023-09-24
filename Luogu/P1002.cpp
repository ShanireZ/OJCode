#include <algorithm>
#include <iostream>
using namespace std;
long long dp[25][25];
int py[10][2] = {{0, 0}, {1, 2}, {2, 1}, {-1, 2}, {-2, 1}, {1, -2}, {2, -1}, {-1, -2}, {-2, -1}};
int main()
{
    int n, m, cx, cy;
    cin >> n >> m >> cx >> cy;
    dp[1][1] = 1, cx++, cy++;
    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = 1; j <= m + 1; j++)
        {
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
            for (int k = 0; k < 9; k++)
            {
                int nx = cx + py[k][0], ny = cy + py[k][1];
                if (nx == i && ny == j)
                {
                    dp[i][j] = 0;
                    break;
                }
            }
        }
    }
    cout << dp[n + 1][m + 1] << endl;
    return 0;
}
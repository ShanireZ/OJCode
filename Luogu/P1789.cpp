#include <iostream>
using namespace std;
int mc[105][105];
int fire[13][2] = {{-1, -1}, {1, 1}, {-1, 1}, {1, -1}, {0, 0}, {-1, 0}, {-2, 0}, {1, 0}, {2, 0}, {0, -1}, {0, -2}, {0, 1}, {0, 2}};
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int tot = n * n;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        for (int i = 0; i < 13; i++)
        {
            int nx = x + fire[i][0];
            int ny = y + fire[i][1];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && mc[nx][ny] == 0)
            {
                mc[nx][ny] = 1;
                tot--;
            }
        }
    }
    for (int i = 1; i <= k; i++)
    {
        int x, y;
        cin >> x >> y;
        for (int i = -2; i <= 2; i++)
        {
            for (int j = -2; j <= 2; j++)
            {
                int nx = x + i;
                int ny = y + j;
                if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && mc[nx][ny] == 0)
                {
                    mc[nx][ny] = 1;
                    tot--;
                }
            }
        }
    }
    cout << tot;
    return 0;
}
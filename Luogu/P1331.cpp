#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int r, c, cnt, a[1005][1005];
int ms[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // 下上右左
int main()
{
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '#')
            {
                a[i][j] = -1;
            }
        }
    }
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (a[i][j] == -1)
            {
                cnt++;
                a[i][j] = cnt;
                int fw[4] = {0, 0, 0, 0};
                for (int k = 0; k < 4; k++)
                {
                    int nx = i + ms[k][0], ny = j + ms[k][1];
                    while (nx >= 1 && ny >= 1 && nx <= r && ny <= c && a[nx][ny] != 0)
                    {
                        if (a[nx][ny] != -1)
                        {
                            cout << "Bad placement." << endl;
                            return 0;
                        }
                        a[nx][ny] = cnt, fw[k]++;
                        nx += ms[k][0], ny += ms[k][1];
                    }
                }
                for (int nx = i - fw[1]; nx <= i + fw[0]; nx++)
                {
                    for (int ny = j - fw[3]; ny <= j + fw[2]; ny++)
                    {
                        if (a[nx][ny] == 0 || (a[nx][ny] != cnt && a[nx][ny] != -1))
                        {
                            cout << "Bad placement." << endl;
                            return 0;
                        }
                        a[nx][ny] = cnt;
                    }
                }
            }
        }
    }
    cout << "There are " << cnt << " ships." << endl;
    return 0;
}
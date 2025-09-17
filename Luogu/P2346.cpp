#include <algorithm>
#include <iostream>
using namespace std;
int a[5][5], kx1, kx2, ky1, ky2, lmt, ok;
int ms[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void dfs(int step, int now, int x1, int y1, int x2, int y2)
{
    if (step > lmt)
    {
        return;
    }
    for (int i = 1; i <= 4; i++)
    {
        if (a[i][1] == a[i][2] && a[i][2] == a[i][3] && a[i][3] == a[i][4])
        {
            cout << step << endl;
            ok = 1;
            return;
        }
        if (a[1][i] == a[2][i] && a[2][i] == a[3][i] && a[3][i] == a[4][i])
        {
            cout << step << endl;
            ok = 1;
            return;
        }
    }
    if (a[1][1] == a[2][2] && a[2][2] == a[3][3] && a[3][3] == a[4][4])
    {
        cout << step << endl;
        ok = 1;
        return;
    }
    if (a[1][4] == a[2][3] && a[2][3] == a[3][2] && a[3][2] == a[4][1])
    {
        cout << step << endl;
        ok = 1;
        return;
    }
    for (int i = 0; i < 4 && ok == 0; i++)
    {
        int nx1 = x1 + ms[i][0], ny1 = y1 + ms[i][1];
        if (nx1 < 1 || nx1 > 4 || ny1 < 1 || ny1 > 4 || a[nx1][ny1] != now)
        {
            continue;
        }
        swap(a[x1][y1], a[nx1][ny1]);
        dfs(step + 1, 3 - now, nx1, ny1, x2, y2);
        swap(a[x1][y1], a[nx1][ny1]);
    }
    for (int i = 0; i < 4 && ok == 0; i++)
    {
        int nx2 = x2 + ms[i][0], ny2 = y2 + ms[i][1];
        if (nx2 < 1 || nx2 > 4 || ny2 < 1 || ny2 > 4 || a[nx2][ny2] != now)
        {
            continue;
        }
        swap(a[x2][y2], a[nx2][ny2]);
        dfs(step + 1, 3 - now, x1, y1, nx2, ny2);
        swap(a[x2][y2], a[nx2][ny2]);
    }
}
int main()
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            char ch;
            cin >> ch;
            if (ch == 'B')
            {
                a[i][j] = 1;
            }
            else if (ch == 'W')
            {
                a[i][j] = 2;
            }
            if (a[i][j] == 0)
            {
                swap(kx1, kx2), swap(ky1, ky2);
                kx1 = i, ky1 = j;
            }
        }
    }
    while (ok == 0)
    {
        dfs(0, 1, kx1, ky1, kx2, ky2);
        if (ok == 0)
        {
            dfs(0, 2, kx1, ky1, kx2, ky2);
        }
        lmt++;
    }
    return 0;
}
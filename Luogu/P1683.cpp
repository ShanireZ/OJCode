#include <iostream>
using namespace std;
int m[25][25], vis[25][25], f[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int sx, sy, cnt, h, w;
void dfs(int x, int y)
{
    cnt++;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + f[i][0], ny = y + f[i][1];
        if (nx < 1 || ny < 1 || nx > h || ny > w || m[nx][ny] == 1 || vis[nx][ny])
        {
            continue;
        }
        dfs(nx, ny);
    }
}
int main()
{
    cin >> w >> h;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '@')
            {
                sx = i, sy = j;
            }
            else if (ch == '#')
            {
                m[i][j] = 1;
            }
        }
    }
    dfs(sx, sy);
    cout << cnt << endl;
    return 0;
}
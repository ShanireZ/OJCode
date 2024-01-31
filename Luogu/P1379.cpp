#include <iostream>
using namespace std;
int now[5][5], ans[5][5] = {{0}, {0, 1, 2, 3}, {0, 8, 0, 4}, {0, 7, 6, 5}};
int ms[5][2] = {{0}, {1, 0}, {0, 1}, {0, -1}, {-1, 0}}, lim, sx, sy;
int dfs(int x, int y, int step, int f)
{
    int cnt = 0; // 记录当前差异个数
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cnt += (now[i][j] != ans[i][j]);
        }
    }
    if (cnt == 0) // 无差异已达成
    {
        return 1;
    }
    if (cnt - 1 + step > lim) // A*剪枝
    {
        return 0;
    }
    for (int i = 1; i <= 4; i++)
    {
        int nx = x + ms[i][0], ny = y + ms[i][1];
        if (nx > 3 || ny > 3 || nx < 1 || ny < 1 || f + i == 5)
        {
            continue;
        }
        swap(now[x][y], now[nx][ny]);
        int ok = dfs(nx, ny, step + 1, i);
        swap(now[nx][ny], now[x][y]); // 回溯复原
        if (ok)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            char ch;
            cin >> ch;
            now[i][j] = ch - '0';
            if (now[i][j] == 0)
            {
                sx = i, sy = j;
            }
        }
    }
    while (true)
    {
        if (dfs(sx, sy, 0, 10))
        {
            cout << lim << endl;
            break;
        }
        lim++; // 限制逐步解除至最少步数
    }
    return 0;
}
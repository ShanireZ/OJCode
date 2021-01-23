#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct Block
{
    int color, x, y;
    bool check = false;
};
Block blocks[105][105];
queue<Block> judge;
int flags[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m, total = 0;

void bfs(int x, int y)
{
    judge.push(blocks[x][y]);
    while (judge.empty() != true)
    {
        x = judge.front().x;
        y = judge.front().y;
        for (int i = 0; i < 4; i++)
        {
            int tmp_x = x + flags[i][0];
            int tmp_y = y + flags[i][1];
            if (tmp_x >= 1 && tmp_x <= n && tmp_y >= 1 && tmp_y <= m)
            {
                if (blocks[tmp_x][tmp_y].check == false && blocks[tmp_x][tmp_y].color == 1)
                {
                    blocks[tmp_x][tmp_y].check = true;
                    judge.push(blocks[tmp_x][tmp_y]);
                }
            }
        }
        judge.pop();
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> blocks[i][j].color;
            blocks[i][j].x = i;
            blocks[i][j].y = j;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (blocks[i][j].check == false && blocks[i][j].color == 1)
            {
                total++;
                blocks[i][j].check = true;
                bfs(i, j);
            }
        }
    }
    cout << total;
    return 0;
}
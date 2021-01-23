#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
using namespace std;
struct Block
{
    int x, y, step = -1;
    bool trig;
};
Block blocks[405][405];
queue<Block> judge;
int flags[8][2] = {{1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};
int n, m;

void bfs(int x, int y)
{
    judge.push(blocks[x][y]);
    while (judge.empty() == false)
    {
        x = judge.front().x;
        y = judge.front().y;
        int step = judge.front().step + 1;
        for (int i = 0; i < 8; i++)
        {
            int tmp_x = x + flags[i][0];
            int tmp_y = y + flags[i][1];
            if (blocks[tmp_x][tmp_y].trig == false)
            {
                if (tmp_x >= 1 && tmp_x <= n && tmp_y >= 1 && tmp_y <= m)
                {
                    blocks[tmp_x][tmp_y].trig = true;
                    blocks[tmp_x][tmp_y].step = step;
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
            blocks[i][j].x = i;
            blocks[i][j].y = j;
        }
    }
    int pos_x, pos_y;
    cin >> pos_x >> pos_y;
    blocks[pos_x][pos_y].trig = true;
    blocks[pos_x][pos_y].step = 0;
    bfs(pos_x, pos_y);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout.width(5);
            cout.setf(ios::left);
            cout.fill(' ');
            cout << blocks[i][j].step;
        }
        cout << endl;
    }
    return 0;
}
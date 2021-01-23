#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct Block
{
    int x, y, color;
    bool trig, outside; //trig标记是否判断过，剪枝用  outside标记是否为外围0
};
Block blocks[32][32];
queue<Block> judge;
int flags[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n;

void bfs(int x, int y)
{
    judge.push(blocks[x][y]);
    while (judge.empty() == false)
    {
        x = judge.front().x;
        y = judge.front().y;
        for (int i = 0; i < 4; i++)
        {
            int tmp_x = x + flags[i][0];
            int tmp_y = y + flags[i][1];
            if (blocks[tmp_x][tmp_y].trig == false && blocks[tmp_x][tmp_y].color == 0)
            {
                if (tmp_x >= 1 && tmp_x <= n && tmp_y >= 1 && tmp_y <= n)
                {
                    blocks[tmp_x][tmp_y].trig = true;
                    blocks[tmp_x][tmp_y].outside = true;
                    judge.push(blocks[tmp_x][tmp_y]);
                }
            }
        }
        judge.pop();
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> blocks[i][j].color;
            blocks[i][j].x = i;
            blocks[i][j].y = j;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 || i == n || j == 1 || j == n) //不用填充的0只会在外围，而且肯定和最外围的0相连
            {
                if (blocks[i][j].color == 0 && blocks[i][j].trig == false)
                {
                    blocks[i][j].trig = true;
                    blocks[i][j].outside = true;
                    bfs(i, j);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (blocks[i][j].outside == true) //外围0不需填充
            {
                cout << "0 ";
            }
            else if (blocks[i][j].color == 1) //1不用填充为2
            {
                cout << "1 ";
            }
            else
            {
                cout << "2 ";
            }
        }
        cout << endl;
    }
    return 0;
}
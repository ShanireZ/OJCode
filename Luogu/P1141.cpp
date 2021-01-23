#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

struct Block
{
    int x, y, color, total;
    bool trig;
};
Block blocks[1005][1005];
queue<Block> judge;
queue<Block> done;
int flags[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m;

void bfs(int x, int y)
{
    judge.push(blocks[x][y]);
    while (judge.empty() == false)
    {
        x = judge.front().x;
        y = judge.front().y;
        int color = judge.front().color;
        for (int i = 0; i < 4; i++)
        {
            int tmp_x = x + flags[i][0];
            int tmp_y = y + flags[i][1];
            if (blocks[tmp_x][tmp_y].trig == false && blocks[tmp_x][tmp_y].color != color)
            {
                if (tmp_x >= 1 && tmp_x <= n && tmp_y >= 1 && tmp_y <= n)
                {
                    blocks[tmp_x][tmp_y].trig = true;
                    judge.push(blocks[tmp_x][tmp_y]);
                }
            }
        }
        done.push(judge.front());
        judge.pop();
    }
    int total = done.size();
    while (done.empty() == false)
    {
        x = done.front().x;
        y = done.front().y;
        blocks[x][y].total = total;
        done.pop();
    }
    cout << total << endl;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char tmp;
            cin >> tmp;
            blocks[i][j].color = tmp - '0';
            blocks[i][j].x = i;
            blocks[i][j].y = j;
        }
    }
    for (; m > 0; m--)
    {
        int pos_x, pos_y;
        cin >> pos_x >> pos_y;
        if (blocks[pos_x][pos_y].trig == true)
        {
            cout << blocks[pos_x][pos_y].total << endl;
            continue;
        }
        blocks[pos_x][pos_y].trig = true;
        bfs(pos_x, pos_y);
    }
    return 0;
}
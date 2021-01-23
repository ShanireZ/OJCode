#include <iostream>
#include <queue>
#include <fstream>
using namespace std;
int moves[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int step[305][305], type[305][305]; //每个点的最少步数和种类
struct Tran
{
    int x1, x2, y1, y2, ok;
};
Tran trans[30]; //传送门坐标 ok表示是否成对
struct Node
{
    int x, y;
};
queue<Node> q;
int main()
{
    int n, m, sx, sy, ex, ey;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            step[i][j] = 0x3f3f3f3f;
            char ch;
            cin >> ch;
            if (ch == '#') //不可访问 50
            {
                type[i][j] = 50;
            }
            else if (ch == '@') //起点 0  其他 0
            {
                sx = i, sy = j;
                step[sx][sy] = 0;
            }
            else if (ch == '=') //终点 0
            {
                ex = i, ey = j;
            }
            else if (ch >= 'A' && ch <= 'Z') //传送门 1-26
            {
                int id = ch - 'A' + 1;
                type[i][j] = id;
                if (trans[id].x1 == 0)
                {
                    trans[id].x1 = i, trans[id].y1 = j;
                }
                else
                {
                    trans[id].x2 = i, trans[id].y2 = j, trans[id].ok = 1;
                }
            }
        }
    }
    Node tmp;
    tmp.x = sx, tmp.y = sy;
    q.push(tmp);
    while (q.size())
    {
        int x = q.front().x, y = q.front().y;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + moves[i][0], ny = y + moves[i][1], id = type[nx][ny];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && id != 50)
            {
                if (trans[id].ok == 1) //如果走到OK的传送门上 必须立刻传送
                {
                    if (nx == trans[id].x1 && ny == trans[id].y1)
                    {
                        nx = trans[id].x2, ny = trans[id].y2;
                    }
                    else
                    {
                        nx = trans[id].x1, ny = trans[id].y1;
                    }
                }
                if (step[nx][ny] > step[x][y] + 1)
                {
                    step[nx][ny] = step[x][y] + 1;
                    Node tmp;
                    tmp.x = nx, tmp.y = ny;
                    q.push(tmp);
                }
            }
        }
    }
    cout << step[ex][ey] << endl;
    return 0;
}
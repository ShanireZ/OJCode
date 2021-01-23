#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct Node
{
    int x, y, h, step;
};
Node nodes[105][105];
queue<Node> way;
int pos[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int main()
{
    ios::sync_with_stdio(false);
    int r, c;
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> nodes[i][j].h;
            nodes[i][j].x = i;
            nodes[i][j].y = j;
        }
    }
    int max_step = 0;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (nodes[i][j].step == 0)
            {
                nodes[i][j].step = 1;
                way.push(nodes[i][j]);
                while (way.size() != 0)
                {
                    int ox = way.front().x;
                    int oy = way.front().y;
                    int ostep = way.front().step;
                    if (ostep > max_step)
                    {
                        max_step = ostep;
                    }
                    for (int k = 0; k < 4; k++)
                    {
                        int x = ox + pos[k][0];
                        int y = oy + pos[k][1];
                        if (x < 1 || x > r || y < 1 || y > c)
                        {
                            continue;
                        }
                        if (nodes[x][y].step < ostep + 1 && nodes[x][y].h < nodes[ox][oy].h)
                        {
                            nodes[x][y].step = ostep + 1;
                            way.push(nodes[x][y]);
                        }
                    }
                    way.pop();
                }
            }
        }
    }
    cout << max_step;
    return 0;
}
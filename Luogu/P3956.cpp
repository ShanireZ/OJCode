#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct Node
{
    int x, y, c, cost;
};
int moves[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
Node maps[105][105];
queue<Node> ways;
int minCost = 0x3f3f3f3f;
int main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            maps[i][j].x = i;
            maps[i][j].y = j;
            maps[i][j].c = -1;
            maps[i][j].cost = 0x3f3f3f3f;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        maps[tmp1][tmp2].c = tmp3;
    }
    maps[1][1].cost = 0;
    ways.push(maps[1][1]);
    while (ways.size())
    {
        if (ways.front().x == m && ways.front().y == m)
        {
            minCost = min(minCost, ways.front().cost);
        }
        for (int i = 0; i < 4; i++)
        {
            int posX = ways.front().x + moves[i][0];
            int posY = ways.front().y + moves[i][1];
            if (posX > 0 && posX <= m && posY > 0 && posY <= m)
            {
                if (maps[posX][posY].c == ways.front().c)
                {
                    if (ways.front().cost < maps[posX][posY].cost)
                    {
                        maps[posX][posY].cost = ways.front().cost;
                        ways.push(maps[posX][posY]);
                    }
                }
                else if (maps[posX][posY].c != ways.front().c)
                {
                    if (maps[posX][posY].c == -1 && maps[ways.front().x][ways.front().y].c == -1)
                    {
                        continue;
                    }
                    Node tmp = maps[posX][posY];
                    tmp.cost = ways.front().cost + 1;
                    if (maps[posX][posY].c == -1)
                    {
                        tmp.cost++;
                        tmp.c = ways.front().c;
                    }
                    if (maps[posX][posY].cost > tmp.cost)
                    {
                        maps[posX][posY].cost = tmp.cost;
                        ways.push(tmp);
                    }
                }
            }
        }
        ways.pop();
    }
    if (minCost == 0x3f3f3f3f)
    {
        cout << -1;
    }
    else
    {
        cout << minCost;
    }
    return 0;
}
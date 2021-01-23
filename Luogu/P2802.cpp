#include <iostream>
#include <algorithm>
using namespace std;
struct Node
{
    int v, usd, hp;
};
Node nodes[15][15];
int moves[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m, sx, sy, mstep;
void dfs(int step, int hp, int x, int y)
{
    if (hp == 0)
    {
        return;
    }
    if (nodes[x][y].v == 3)
    {
        mstep = min(mstep, step);
        return;
    }
    if (nodes[x][y].v == 4)
    {
        hp = 6;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + moves[i][0];
        int ny = y + moves[i][1];
        if (nx >= 1 && ny >= 1 && nx <= n && ny <= m && nodes[nx][ny].v != 0)
        {
            if (nodes[nx][ny].usd == 0)
            {
                nodes[nx][ny].usd = 1;
                nodes[nx][ny].hp = hp - 1;
                dfs(step + 1, hp - 1, nx, ny);
                nodes[nx][ny].usd = 0;
            }
            else if (nodes[nx][ny].hp < hp - 1)
            {
                nodes[nx][ny].hp = hp - 1;
                dfs(step + 1, hp - 1, nx, ny);
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> nodes[i][j].v;
            if (nodes[i][j].v == 2)
            {
                sx = i;
                sy = j;
            }
        }
    }
    mstep = 0x3f3f3f3f;
    nodes[sx][sy].usd = 1;
    dfs(0, 6, sx, sy);
    if (mstep == 0x3f3f3f3f)
    {
        mstep = -1;
    }
    cout << mstep;
    return 0;
}
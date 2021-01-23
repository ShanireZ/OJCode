#include <iostream>
using namespace std;
struct Node
{
    int x, y, checked, forbid;
};
Node nodes[6][6];
int moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int sx, sy, fx, fy;
int n, m, t;
int total;

void makeway(int x, int y)
{
    if (x == fx && y == fy)
    {
        total++;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + moves[i][0];
        int ny = y + moves[i][1];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && nodes[nx][ny].forbid == 0 && nodes[nx][ny].checked == 0)
        {
            nodes[nx][ny].checked = 1;
            makeway(nx, ny);
            nodes[nx][ny].checked = 0;
        }
    }
}

int main()
{
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            nodes[i][j].x = i;
            nodes[i][j].y = j;
        }
    }
    for (int i = 1; i <= t; i++)
    {
        int a, b;
        cin >> a >> b;
        nodes[a][b].forbid = 1;
    }
    nodes[sx][sy].checked = 1;
    makeway(sx, sy);
    cout << total;
    return 0;
}
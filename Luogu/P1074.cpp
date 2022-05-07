#include <algorithm>
#include <iostream>
using namespace std;
int sd[10][10], h[10][10], l[10][10], b[10][10];
int ans = -1, pos;
struct Node
{
    int x, y;
};
Node ns[100];
struct Line
{
    int t, id;
    bool operator<(const Line oth) const
    {
        return t > oth.t;
    }
};
Line ls[10];
int queryex(int x, int y)
{
    if (x == 5 && y == 5)
    {
        return 10;
    }
    else if (x >= 4 && x <= 6 && y >= 4 && y <= 6)
    {
        return 9;
    }
    else if (x >= 3 && x <= 7 && y >= 3 && y <= 7)
    {
        return 8;
    }
    else if (x >= 2 && x <= 8 && y >= 2 && y <= 8)
    {
        return 7;
    }
    return 6;
}
void dfs(int id, int tot)
{
    if (id > pos)
    {
        ans = max(ans, tot);
        return;
    }
    int x = ns[id].x, y = ns[id].y;
    int block = (x - 1) / 3 * 3 + (y - 1) / 3 + 1;
    for (int i = 1; i <= 9; i++)
    {
        if (h[x][i] || l[y][i] || b[block][i])
        {
            continue;
        }
        h[x][i] = l[y][i] = b[block][i] = 1;
        dfs(id + 1, tot + queryex(x, y) * i);
        h[x][i] = l[y][i] = b[block][i] = 0;
    }
}
int main()
{
    for (int i = 1; i <= 9; i++)
    {
        ls[i].id = i;
        for (int j = 1; j <= 9; j++)
        {
            cin >> sd[i][j];
            if (sd[i][j] != 0)
            {
                ls[i].t++;
            }
        }
    }
    sort(ls + 1, ls + 10);
    int tot = 0;
    for (int i = 1; i <= 9; i++)
    {
        int x = ls[i].id;
        for (int y = 1; y <= 9; y++)
        {
            if (sd[x][y] != 0)
            {
                int block = (x - 1) / 3 * 3 + (y - 1) / 3 + 1, n = sd[x][y];
                b[block][n] = h[x][n] = l[y][n] = 1;
                tot += queryex(x, y) * sd[x][y];
            }
            else
            {
                ns[++pos] = {x, y};
            }
        }
    }
    dfs(1, tot);
    cout << ans << endl;
    return 0;
}
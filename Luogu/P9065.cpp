#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int x, y;
};
Node pos[9000005];
queue<Node> q;
int read(), h[3005][3005], dis[3005][3005], fly[3005][3005], h1[9000005], ok;
int ms[5][5] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int main()
{
    int n = read(), m = read(), k = read();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            h[i][j] = read();
        }
    }
    for (int i = 1; i <= k; i++)
    {
        pos[i].x = read(), pos[i].y = read();
        fly[pos[i].x][pos[i].y] = 1;
    }
    memset(dis, 0x3f, sizeof(dis));
    q.push(Node{1, 1}), dis[1][1] = 0;
    while (q.size()) // 每个点入队出队一次 O(n*m)
    {
        int x = q.front().x, y = q.front().y;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + ms[i][0], ny = y + ms[i][1];
            if (nx >= 1 && ny >= 1 && nx <= n && ny <= m && h[nx][ny] != 0 && dis[nx][ny] > dis[x][y] + 1)
            {
                q.push(Node{nx, ny}), dis[nx][ny] = dis[x][y] + 1;
                if ((ok == 0 || ok == dis[nx][ny]) && fly[nx][ny])
                {
                    ok = dis[nx][ny], h1[h[nx][ny]] = 1;
                }
            }
        }
        if (fly[x][y] && ok) // 仅处理一次所有点的御剑情况 O(k)
        {
            ok = 0;
            for (int i = 1; i <= k; i++)
            {
                int nx = pos[i].x, ny = pos[i].y;
                if (h1[h[nx][ny]] && dis[nx][ny] > dis[x][y] + 1)
                {
                    q.push(Node{nx, ny}), dis[nx][ny] = dis[x][y] + 1;
                }
                else if (h1[h[nx][ny]] == 0 && dis[nx][ny] > dis[x][y] + 2)
                {
                    q.push(Node{nx, ny}), dis[nx][ny] = dis[x][y] + 2;
                }
            }
        }
    }
    printf("%d\n", (dis[n][m] == 0x3f3f3f3f ? -1 : dis[n][m]));
    return 0;
}
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}
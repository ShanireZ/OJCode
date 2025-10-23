#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Edge
{
    int x, y;
    long long w;
    bool operator<(const Edge &oth) const
    {
        return w > oth.w;
    }
};
vector<Edge> es[15][15];
int n, m, pos, k[15][2], mp[15][15], ans[15][15], from[15][15][1100][3], ms[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
long long dp[15][15][1100];
priority_queue<Edge> pq;
queue<Edge> q;
void dijkstra(int sta)
{
    while (pq.size())
    {
        int x = pq.top().x, y = pq.top().y;
        long long dis = pq.top().w;
        pq.pop();
        if (dis == dp[x][y][sta])
        {
            for (Edge e : es[x][y])
            {
                int nx = e.x, ny = e.y;
                if (dp[nx][ny][sta] > dp[x][y][sta] + e.w)
                {
                    from[nx][ny][sta][2] = 0;
                    from[nx][ny][sta][0] = x, from[nx][ny][sta][1] = y;
                    dp[nx][ny][sta] = dp[x][y][sta] + e.w;
                    pq.push(Edge{nx, ny, dp[nx][ny][sta]});
                }
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mp[i][j];
            if (mp[i][j] == 0)
            {
                pos++;
                k[pos][0] = i, k[pos][1] = j;
                dp[i][j][1 << (pos - 1)] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int f = 0; f < 4; f++)
            {
                int ni = i + ms[f][0], nj = j + ms[f][1];
                if (ni >= 1 && ni <= n && nj >= 1 && nj <= m)
                {
                    es[i][j].push_back(Edge{ni, nj, mp[ni][nj]});
                    es[ni][nj].push_back(Edge{i, j, mp[i][j]});
                }
            }
        }
    }
    for (int sta = 1; sta < (1 << pos); sta++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                for (int pre = sta & (sta - 1); pre; pre = sta & (pre - 1))
                {
                    if (dp[i][j][sta] > dp[i][j][pre] + dp[i][j][sta ^ pre] - mp[i][j])
                    {
                        dp[i][j][sta] = dp[i][j][pre] + dp[i][j][sta ^ pre] - mp[i][j];
                        from[i][j][sta][0] = pre, from[i][j][sta][2] = sta ^ pre;
                    }
                }
                if (dp[i][j][sta] != 0x3f3f3f3f3f3f3f3f)
                {
                    pq.push(Edge{i, j, dp[i][j][sta]});
                }
            }
        }
        dijkstra(sta);
    }
    cout << (pos ? dp[k[1][0]][k[1][1]][(1 << pos) - 1] : 0) << endl;
    if (pos)
    {
        q.push(Edge{k[1][0], k[1][1], (1 << pos) - 1});
    }
    while (q.size())
    {
        int x = q.front().x, y = q.front().y, sta = q.front().w;
        q.pop(), ans[x][y] = 1;
        for (int i = 1; i <= pos; i++)
        {
            if (x == k[i][0] && y == k[i][1] && (sta ^ (1 << (i - 1))) < sta)
            {
                sta ^= (1 << (i - 1));
                break;
            }
        }
        if (from[x][y][sta][1])
        {
            q.push(Edge{from[x][y][sta][0], from[x][y][sta][1], sta});
        }
        else if (from[x][y][sta][2])
        {
            q.push(Edge{x, y, from[x][y][sta][0]});
            q.push(Edge{x, y, from[x][y][sta][2]});
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << (ans[i][j] ? (mp[i][j] == 0 ? "x" : "o") : "_");
        }
        cout << endl;
    }
    return 0;
}
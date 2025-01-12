#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int x, y, step, fw;
    bool operator<(const Node &oth) const
    {
        return step > oth.step;
    }
};
priority_queue<Node> q;
int n, m, sx, sy, fx, fy, mp[1005][1005], dp[1005][1005][2];
int ms[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char ch;
            cin >> ch;
            if (ch == 'S')
            {
                sx = i, sy = j;
            }
            else if (ch == 'G')
            {
                fx = i, fy = j;
            }
            else if (ch == '#')
            {
                mp[i][j] = 1;
            }
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    q.emplace(Node{sx, sy, 0, 0}), q.emplace(Node{sx, sy, 0, 1});
    dp[sx][sy][0] = dp[sx][sy][1] = 0;
    while (q.size())
    {
        int x = q.top().x, y = q.top().y, step = q.top().step, fw = q.top().fw;
        q.pop();
        if (dp[x][y][fw] != step)
        {
            continue;
        }
        for (int i = fw * 2; i < fw * 2 + 2; i++)
        {
            int nx = x + ms[i][0], ny = y + ms[i][1];
            if (nx <= n && ny <= m && nx >= 1 && ny >= 1 && mp[nx][ny] == 0)
            {
                if (dp[nx][ny][!fw] > step + 1)
                {
                    dp[nx][ny][!fw] = step + 1;
                    q.emplace(Node{nx, ny, step + 1, !fw});
                }
            }
        }
    }
    int ans = min(dp[fx][fy][0], dp[fx][fy][1]);
    cout << (ans == 0x3f3f3f3f ? -1 : ans) << endl;
    return 0;
}
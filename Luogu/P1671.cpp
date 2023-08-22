#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
struct Node
{
    int x, y;
    bool operator<(const Node &oth) const
    {
        if (x == oth.x)
        {
            return y < oth.y;
        }
        return x < oth.x;
    }
};
Node pos[10], tmp[10];
set<long long> s;
int mp[10][10], vis[10][10], ms[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void dfs(int x, int y, int cnt, int step)
{
    pos[step].x = x, pos[step].y = y;
    if (step == 7)
    {
        if (cnt > 3)
        {
            for (int i = 1; i <= 7; i++)
            {
                tmp[i] = pos[i];
            }
            sort(tmp + 1, tmp + 8);
            long long ans = 0;
            for (int i = 1; i <= 7; i++)
            {
                ans = (ans * 6 + tmp[i].x) * 6 + tmp[i].y;
            }
            s.insert(ans);
        }
        return;
    }
    vis[x][y] = 1;
    for (int k = 1; k <= step; k++)
    {
        for (int i = 0; i < 4; i++)
        {
            int nx = pos[k].x + ms[i][0], ny = pos[k].y + ms[i][1];
            if (vis[nx][ny] == 0 && nx >= 1 && ny >= 1 && nx <= 5 && ny <= 5)
            {
                dfs(nx, ny, cnt + mp[nx][ny], step + 1);
            }
        }
    }
    vis[x][y] = 0;
}
int main()
{
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            char ch;
            cin >> ch;
            mp[i][j] = (ch == 'J');
        }
    }
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            if (mp[i][j])
            {
                dfs(i, j, 1, 1);
            }
        }
    }
    cout << s.size() << "\n";
    return 0;
}
// TAG: DFS 搜索 哈希 状态压缩 枚举
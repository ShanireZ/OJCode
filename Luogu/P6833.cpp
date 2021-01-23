#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int read() //快读
{
    char ch = getchar();
    while ((ch > '9' || ch < '0') && ch != '-')
    {
        ch = getchar();
    }
    int t = 1, n = 0;
    if (ch == '-')
    {
        t = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        n = n * 10 + ch - '0';
        ch = getchar();
    }
    return n * t;
}
struct Node
{
    long long d[3], v;
};
Node mp[1005][1005];
struct Point
{
    int x, y;
    long long d;
};
struct cmp
{
    bool operator()(const Point x, const Point y)
    {
        return x.d > y.d;
    }
};
priority_queue<Point, vector<Point>, cmp> pt;
int mx[4] = {0, 0, 1, -1};
int my[4] = {1, -1, 0, 0};
int n, m, a, b, c;
void make(int h, int l, int id)
{
    mp[h][l].d[id] = mp[h][l].v;
    Point tmp;
    tmp.x = h, tmp.y = l;
    tmp.d = mp[h][l].d[id];
    pt.push(tmp);
    while (pt.size())
    {
        int x = pt.top().x;
        int y = pt.top().y;
        pt.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + mx[i];
            int ny = y + my[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
            {
                long long d = mp[nx][ny].v + mp[x][y].d[id];
                if (d < mp[nx][ny].d[id])
                {
                    mp[nx][ny].d[id] = d;
                    tmp.x = nx, tmp.y = ny;
                    tmp.d = d;
                    pt.push(tmp);
                }
            }
        }
    }
}
int main()
{
    n = read(), m = read(), a = read(), b = read(), c = read();
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= m; j++)
        {
            mp[i][j].v = read();
            mp[i][j].d[0] = mp[i][j].d[1] = mp[i][j].d[2] = 1e18;
        }
    }
    make(n, a, 0);
    make(1, b, 1);
    make(1, c, 2);
    long long ans = 1e18;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            long long tot = mp[i][j].d[0] + mp[i][j].d[1] + mp[i][j].d[2] - mp[i][j].v * 2;
            ans = min(ans, tot);
        }
    }
    printf("%lld", ans);
    return 0;
}
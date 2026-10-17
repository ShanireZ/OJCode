#include <cstdio>
#include <vector>
using namespace std;
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
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
int vis[3005][3005], ans, n;
int ms[5][2] = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void dfs(int x, int y) //驗證x y位置是否為舒適點 如果true則加點改造 然後遞歸驗證新點及新點周圍
{
    if (vis[x][y] == 0)
    {
        return;
    }
    int t = 0, tx, ty;
    for (int i = 1; i <= 4; i++)
    {
        int nx = x + ms[i][0], ny = y + ms[i][1];
        if (vis[nx][ny])
        {
            t++;
        }
        else
        {
            tx = nx, ty = ny;
        }
    }
    if (t == 3)
    {
        vis[tx][ty] = 1;
        ans++;
        for (int i = 0; i <= 4; i++)
        {
            int nx = tx + ms[i][0], ny = ty + ms[i][1];
            dfs(nx, ny);
        }
    }
}
int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
    {
        int x = read(), y = read();
        x += 1000, y += 1000;
        if (vis[x][y] == 1) //如果之前的加點被新點替換
        {
            ans--;
        }
        vis[x][y] = 1;
        for (int j = 0; j <= 4; j++) //檢測新點及周圍點是否舒適
        {
            int nx = x + ms[j][0], ny = y + ms[j][1];
            dfs(nx, ny);
        }
        printf("%d\n", ans);
    }
    return 0;
}
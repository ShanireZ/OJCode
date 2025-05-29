#include <algorithm>
#include <iostream>
using namespace std;
long long a[25][25], vis[25][25], h, w, ans, sum;
void dfs(int x, int y)
{
    ans = max(ans, sum);
    if (x == h && y == w)
    {
        return;
    }
    int nx = y < w ? x : x + 1, ny = y < w ? y + 1 : 1;
    dfs(nx, ny);                                        // 不放置
    if (vis[x][y] == 0 && x != h && vis[x + 1][y] == 0) // 竖着放置
    {
        vis[x + 1][y] = 1, sum ^= a[x][y] ^ a[x + 1][y];
        dfs(nx, ny);
        vis[x + 1][y] = 0, sum ^= a[x][y] ^ a[x + 1][y];
    }
    if (vis[x][y] == 0 && y != w && vis[x][y + 1] == 0) // 横着放置
    {
        vis[x][y + 1] = 1, sum ^= a[x][y] ^ a[x][y + 1];
        dfs(nx, ny);
        vis[x][y + 1] = 0, sum ^= a[x][y] ^ a[x][y + 1];
    }
}
int main()
{
    cin >> h >> w;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            cin >> a[i][j];
            sum ^= a[i][j];
        }
    }
    dfs(1, 1);
    cout << ans << endl;
    return 0;
}
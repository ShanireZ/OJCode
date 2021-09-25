#include <iostream>
using namespace std;
struct Node
{
    int x, y, stop, vis;
};
Node ns[10][10];
int sx, sy, fx, fy, n, m, t, ans;
int ms[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
void findway(int x, int y)
{
    if (x == fx && y == fy)
    {
        ans++;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + ms[i][0], ny = y + ms[i][1];
        if (nx < 1 || nx > n || ny < 1 || ny > m ||
            ns[nx][ny].vis == 1 || ns[nx][ny].stop == 1)
        {
            continue;
        }
        ns[nx][ny].vis = 1;
        findway(nx, ny);
        ns[nx][ny].vis = 0;
    }
}
int main()
{
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;
    for (int i = 1; i <= t; i++)
    {
        int x, y;
        cin >> x >> y;
        ns[x][y].stop = 1;
    }
    ns[sx][sy].vis = 1;
    findway(sx, sy);
    cout << ans << endl;
    return 0;
}
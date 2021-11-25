#include <iostream>
using namespace std;
int cnt[1005][1005], vis[1005][1005];
int ms[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int main()
{
    int n, tot = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        x++, y++;
        vis[x][y] = 1;
        for (int j = 0; j < 4; j++)
        {
            int nx = x + ms[j][0], ny = y + ms[j][1];
            cnt[nx][ny]++;
            if (cnt[nx][ny] == 3 && vis[nx][ny])
            {
                tot++;
            }
            else if (cnt[nx][ny] > 3 && vis[nx][ny])
            {
                tot--;
            }
        }
        if (cnt[x][y] == 3)
        {
            tot++;
        }
        cout << tot << endl;
    }
    return 0;
}
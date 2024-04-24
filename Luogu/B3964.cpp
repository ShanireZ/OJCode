#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int col[1005][1005], hg[1005][1005], n, m, k;
int main()
{
    memset(hg, 0x3f, sizeof(hg));
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
    {
        int x, y, h, c;
        cin >> x >> y >> h >> c;
        if (hg[x][y] > h)
        {
            hg[x][y] = h, col[x][y] = c;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << col[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
#include <iostream>
#include <cstring>
using namespace std;
int st[105][105];
int trans[105][105];
int main()
{
    int n, m;
    cin >> n >> m;
    memset(st, 0x3f, sizeof(st));
    for (int i = 1; i <= n; i++)
    {
        st[i][i] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        st[x][y] = st[y][x] = w;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                st[i][j] = min(st[i][j], st[i][k] + st[k][j]);
            }
        }
    }
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int x = 1; x <= n; x++)
            {
                for (int y = 1; y <= n; y++)
                {
                    trans[x][y] = st[x][y];
                }
            }
            trans[i][j] = trans[j][i] = 0;
            for (int x = 1; x <= n; x++)
            {
                for (int y = 1; y <= n; y++)
                {
                    trans[x][y] = min(trans[x][y], trans[x][i] + trans[i][y]);
                }
            }
            for (int x = 1; x <= n; x++)
            {
                for (int y = 1; y <= n; y++)
                {
                    trans[x][y] = min(trans[x][y], trans[x][j] + trans[j][y]);
                }
            }
            int tot = 0;
            for (int x = 1; x <= n; x++)
            {
                for (int y = 1; y < x; y++)
                {
                    tot += trans[x][y];
                }
            }
            ans = min(ans, tot);
        }
    }
    cout << ans;
    return 0;
}
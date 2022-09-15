#include <algorithm>
#include <cstdio>
using namespace std;
inline int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
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
int h[1003][1003], s[1003][1003], ax[1000005], ay[1000005], pos;
int ms[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int main()
{
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            h[i][j] = read();
        }
    }
    int t = read();
    while (t--)
    {
        int x1 = read(), y1 = read(), x2 = read(), y2 = read();
        swap(h[x1][y1], h[x2][y2]);
    }
    int tot = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                int x = i + ms[k][0], y = j + ms[k][1];
                if (x > n || y > m || x < 0 || y < 0)
                {
                    continue;
                }
                if (s[x][y] == 1 || h[x][y] >= h[i][j])
                {
                    s[i][j] = -1;
                    break;
                }
            }
            if (s[i][j] == 0)
            {
                s[i][j] = 1;
                tot++, pos++;
                ax[pos] = i, ay[pos] = j;
            }
        }
    }
    printf("%d\n", tot);
    for (int i = 1; i <= pos; i++)
    {
        printf("%d %d\n", ax[i], ay[i]);
    }
    return 0;
}
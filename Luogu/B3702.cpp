#include <iostream>
using namespace std;
int h[1005][1005], l[1005][1005];
int read()
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
int main()
{
    int m = read(), n = read(), x = read(), y = read();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            h[i][j] = read(), l[i][j] = read();
        }
    }
    printf("%d %d\n", x, y);
    while (h[x][y] || l[x][y])
    {
        int nx = h[x][y], ny = l[x][y];
        x = nx, y = ny;
        printf("%d %d\n", x, y);
    }
    return 0;
}
#include <algorithm>
#include <iostream>
using namespace std;
#define MX 1000005
int col[MX][25], tm[MX][25], n, q, read();
int main()
{
    n = read(), q = read();
    for (int t = 1; t <= q; t++)
    {
        int opt = read(), x = read();
        if (opt == 1)
        {
            int y = read(), z = read();
            while (x > 0 && y >= 0)
            {
                for (int i = 0; i <= min(y, 20); i++) // 防止y过大数组越界
                {
                    col[x][i] = z, tm[x][i] = t;
                }
                x /= 2, y -= 1;
            }
        }
        else
        {
            int dis = 0, c = 0, lastc = 0;
            while (x > 0)
            {
                if (tm[x][dis] > lastc)
                {
                    lastc = tm[x][dis], c = col[x][dis];
                }
                x /= 2, dis += 1;
            }
            printf("%d\n", c);
        }
    }
    return 0;
}
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
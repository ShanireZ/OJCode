#include <algorithm>
#include <iostream>
#include <pthread.h>
using namespace std;
int mp[305][305], r, c, k, res;
int read()
{
    int ans = 0;
    char ch = getchar_unlocked();
    while (ch < '0' || ch > '9')
    {
        ch = getchar_unlocked();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar_unlocked();
    }
    return ans;
}
int main()
{
    r = read(), c = read(), k = read();
    while (r != 0)
    {
        for (int i = 1; i <= r; i++)
        {
            for (int j = 1; j <= c; j++)
            {
                char ch = getchar_unlocked();
                while (ch != '.' && ch != 'X')
                {
                    ch = getchar_unlocked();
                }
                mp[i][j] = (ch == '.') + mp[i - 1][j] + mp[i][j - 1] - mp[i - 1][j - 1];
            }
        }
        res = r * c;
        for (int i = 1; i <= r; i++) // 左上角(i, j)
        {
            for (int j = 1; j <= c; j++)
            {
                for (int x = r, y = j; x >= i; x--) // 右下角(x, y)
                {
                    while (y < c && mp[x][y] - mp[x][j - 1] - mp[i - 1][y] + mp[i - 1][j - 1] < k)
                    {
                        y++;
                    }
                    if (mp[x][y] - mp[x][j - 1] - mp[i - 1][y] + mp[i - 1][j - 1] < k)
                    {
                        break;
                    }
                    res = min(res, (x - i + 1) * (y - j + 1));
                }
            }
        }
        printf("%d\n", res);
        r = read(), c = read(), k = read();
    }
    return 0;
}
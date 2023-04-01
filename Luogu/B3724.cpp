#include <iostream>
using namespace std;
int tot[25][25], read();
int main()
{
    int n = read(), m = read(), k = read(), ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            tot[i][j] = tot[i - 1][j] + tot[i][j - 1] - tot[i - 1][j - 1] + read();
        }
    }
    for (int x = 1; x <= n && x <= ans; x++)
    {
        for (int y = 1; y <= m && x * y <= ans; y++)
        {
            int ok = 1;
            for (int i = 1; i + x - 1 <= n && ok; i++)
            {
                for (int j = 1; j + y - 1 <= n && ok; j++)
                {
                    int sum = tot[i + x - 1][j + y - 1] - tot[i + x - 1][j - 1] - tot[i - 1][j + y - 1] + tot[i - 1][j - 1];
                    if (sum >= k)
                    {
                        ans = min(ans, x * y), ok = 0;
                    }
                }
            }
        }
    }
    cout << ans << "\n";
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
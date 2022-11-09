#include <algorithm>
#include <cstdio>
using namespace std;
inline int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
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
int sql[105][1005];
int main()
{
    int n = read(), k = read();
    for (int i = 1; i <= n; i++)
    {
        int op = read();
        if (op == 1)
        {
            int t = read();
            for (int j = 1; j <= t; j++)
            {
                int x = read(), y = read();
                sql[x][y]++;
            }
        }
        else
        {
            int p = read(), l = read(), r = read(), ans = 0;
            for (int j = l; j <= r; j++)
            {
                ans += sql[p][j];
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
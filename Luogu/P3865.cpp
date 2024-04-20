#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int st[100005][20];
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
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        st[i][0] = read();
    }
    for (int j = 1; j <= 16; j++)
    {
        int pw = pow(2, j);
        for (int i = 1; i + pw - 1 <= n; i++)
        {
            int p = i + pw / 2;
            st[i][j] = max(st[i][j - 1], st[p][j - 1]);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int l = read(), r = read();
        int x = log2(r - l + 1);
        int p = r - pow(2, x) + 1;
        printf("%d\n", max(st[l][x], st[p][x]));
    }
    return 0;
}
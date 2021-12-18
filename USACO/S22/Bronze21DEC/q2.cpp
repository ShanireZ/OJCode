#include <cstdio>
#include <queue>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int read()
{
    char ch = getchar();
    int ans = 0;
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
int p[100005];
int p1[100005], p2[100005]; //正负温差
int main()
{
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        p[i] = read();
    }
    for (int i = 1; i <= n; i++)
    {
        int ex = p[i] - read();
        (ex > 0) ? p1[i] = ex : p2[i] = ex;
    }
    int now = 0, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (p1[i] > p1[i - 1])
        {
            ans += p1[i] - p1[i - 1];
        }
    }
    ans += now;
    now = 0;
    for (int i = 1; i <= n; i++)
    {
        if (p2[i] > p2[i - 1])
        {
            ans += p2[i] - p2[i - 1];
        }
    }
    printf("%d\n", ans);
    return 0;
}
#include <cstdio>
using namespace std;
#define MX 100005
int r[MX], ans[MX];
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
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        int x = read();
        r[x] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        int x = read();
        ans[r[i]] = x;
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", ans[i]);
    }
    return 0;
}
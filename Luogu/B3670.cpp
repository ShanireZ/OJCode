#include <cstdio>
using namespace std;
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
    int n = read(), r = read(), ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int k = read(), p = read();
        if (p <= r && k > ans)
        {
            ans = k;
        }
    }
    printf("%d\n", ans);
    return 0;
}
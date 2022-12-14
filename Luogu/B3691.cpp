#include <iostream>
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
int a[500005], b[5000005];
int main()
{
    int n = read(), m = read(), ans = 0;
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    for (int i = 1; i <= m; i++)
    {
        b[read()] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (b[a[i]])
        {
            a[i] = 0;
        }
        else if (a[i - 1] == 0)
        {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
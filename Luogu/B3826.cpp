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
int main()
{
    int n = read(), ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int a = read(), b = read();
        ans += (b == 0 ? 10 : a);
    }
    printf("%d\n", ans);
    return 0;
}
#include <iostream>
using namespace std;
long long read();
int main()
{
    ios::sync_with_stdio(false);
    int t = read();
    while (t--)
    {
        long long x = read(), ans = 1;
        if (x % 3 == 2)
        {
            printf("0\n");
            continue;
        }
        else if (x % 3 == 1)
        {
            x /= 3;
        }
        while (x)
        {
            if (x % 3 == 1)
            {
                ans *= 2;
            }
            x = x / 3;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
long long read()
{
    long long ans = 0;
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
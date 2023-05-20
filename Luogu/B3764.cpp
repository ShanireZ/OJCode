#include <algorithm>
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
    int t = read();
    while (t--)
    {
        int n = read() - 1;
        unsigned long long ans = 2;
        while (n >= 1)
        {
            ans = ans * n;
            n -= 2;
        }
        printf("%llu\n", ans);
    }
    return 0;
}
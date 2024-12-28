#include <iostream>
using namespace std;
long long ans, r[1000005];
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
    int n = read(), k = read(), tot = 0;
    r[0] = 1;
    while(n--)
    {
        tot = (tot + read()) % k;
        ans += r[tot]++;
    }
    printf("%lld\n", ans);
    return 0;
}
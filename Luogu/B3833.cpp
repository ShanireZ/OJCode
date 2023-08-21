#include <cmath>
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
    int n = read(), cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt += log2(read());
    }
    int s = cnt / n, r = cnt % n;
    long long tot = round(pow(2, s + 1)) * r + round(pow(2, s)) * (n - r);
    printf("%lld\n", tot);
    return 0;
}
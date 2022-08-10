#include <cstdio>
using namespace std;
long long read()
{
    long long ans = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
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
        long long s = read(), m = read();
        if (m > 1 && s % 2 == 0)
        {
            printf("2 %lld %lld\n", s / 2, s / 2);
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}
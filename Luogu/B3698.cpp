#include <iostream>
using namespace std;
long long read()
{
    long long ans = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
        {
            f = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * f;
}
int main()
{
    ios::sync_with_stdio(false);
    long long n = read(), k = read(), b = read(), cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt += (k * read() + b == read());
    }
    printf("%d", cnt);
    return 0;
}
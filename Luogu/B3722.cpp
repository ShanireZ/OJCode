#include <iostream>
using namespace std;
long long a[100005], b;
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
    ios::sync_with_stdio(false);
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = a[i - 1] + read();
    }
    for (int i = 1; i <= n; i++)
    {
        b += read();
        if (b > a[i])
        {
            printf("%d", i);
            return 0;
        }
    }
    return 0;
}
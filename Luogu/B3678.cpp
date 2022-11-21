#include <iostream>
using namespace std;
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}
int a[100005];
int main()
{
    int n = read(), cnt = 0;
    long long x = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    for (int i = 1; i <= n; i++)
    {
        int b = read();
        if (x >= a[i])
        {
            x += b, cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
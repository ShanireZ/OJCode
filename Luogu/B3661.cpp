#include <cstdio>
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
int a[10005], pos;
int main()
{
    int n = read();
    while (n--)
    {
        int x = read();
        (x % 2 == 1) ? printf("%d ", x) : a[++pos] = x;
    }
    printf("\n");
    for (register int i = 1; i <= pos; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
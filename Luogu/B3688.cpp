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
int a[2005];
int main()
{
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    int p = n;
    do
    {
        for (int i = p; i <= n; i++)
        {
            printf("%d ", a[i]);
        }
        for (int i = 1; i < p; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
    } while (a[--p] != n && p);
    return 0;
}
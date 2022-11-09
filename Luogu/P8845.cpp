#include <algorithm>
#include <cstdio>
using namespace std;
inline int read()
{
    int ans = 0;
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
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        int x = read(), y = read();
        if ((x == 1 || y == 1) && x + y == 3)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
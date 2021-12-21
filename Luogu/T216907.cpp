#include <cstdio>
#include <algorithm>
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
    int t = read();
    while (t--)
    {
        int a = read(), p = read();
        if (p < 16)
        {
            a = max(0, a - 10);
        }
        else if (p > 20)
        {
            a = max(0, a - p + 20);
        }
        printf("%d\n", a);
    }
    return 0;
}
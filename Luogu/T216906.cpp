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
    int t = read(), h = read(), e = read();
    int a = t * 0.2 + h * 0.3 + e * 0.5;
    printf("%d\n", a);
    return 0;
}
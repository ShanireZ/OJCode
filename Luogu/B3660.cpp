#include <cstdio>
using namespace std;
inline int read()
{
    register int ans = 0;
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
    register int t = read();
    while (t--)
    {
        int n = read(), ok = 0;
        for (register int i = 1; i <= n; i++)
        {
            ok += !read();
        }
        (ok) ? printf("yes\n") : printf("no\n");
    }
    return 0;
}
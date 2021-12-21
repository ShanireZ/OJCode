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
int s[1005];
int main()
{
    int n = read();
    int smax = 0, smin = 10000;
    for (int i = 1; i <= n; i++)
    {
        s[i] = read();
        smax = max(smax, s[i]);
        smin = min(smin, s[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        s[i] = 100.0 * (s[i] - smin) / (smax - smin);
        printf("%d ", s[i]);
    }
    return 0;
}
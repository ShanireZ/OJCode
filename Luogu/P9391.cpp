#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int a[500005], tag[500005];
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
    int n = read(), m = read(), all = 0;
    for (int i = 1; i <= m; i++)
    {
        int x = read(), cnt = 0, pos = 0;
        if (tag[x] == 0 && all != n)
        {
            do
            {
                cnt += (a[pos] == 0);
                a[pos] = 1;
                pos = (pos + x) % n;
            } while (pos != 0);
            tag[x] = tag[n - x] = 1, all += cnt;
        }
        printf("%d ", cnt);
    }
    return 0;
}
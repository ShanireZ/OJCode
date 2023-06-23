#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int t[1000005], v[1000005];
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
    int T = read();
    while (T--)
    {
        memset(t, 0, sizeof(t));
        int ans = 0, n = read(), st = 1;
        for (int i = 1; i <= n; i++)
        {
            v[i] = read();
            t[v[i]]++;
            while (t[v[i]] > 1)
            {
                t[v[st]]--;
                st++;
            }
            ans = max(ans, i - st + 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}
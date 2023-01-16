#include <iostream>
using namespace std;
int s[1000005];
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
    int n = read(), m = read(), cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        int pos = read();
        for (int j = max(pos - 2, 1); j <= min(pos + 2, n); j++)
        {
            if (s[j] == 0)
            {
                cnt++, s[j] = 1;
            }
        }
    }
    printf("%d", cnt);
    return 0;
}
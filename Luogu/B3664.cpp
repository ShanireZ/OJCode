#include <algorithm>
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
int p[5005];
int main()
{
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    sort(p + 1, p + 1 + n);
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        ans = max(ans, p[i] - p[i - 1]);
    }
    printf("%d\n", ans);
    return 0;
}
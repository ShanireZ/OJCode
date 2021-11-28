#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
int read()
{
    int ans = 0, t = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        t = (ch == '-') ? -1 : 1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * t;
}
int s1[1000005], s2[1000005], sum[1000005], ans[1000005];
int pos1, pos2, n;
int main()
{
    n = read();
    fill(ans, ans + n + 1, -0x3f3f3f3f);
    for (int i = 1; i <= n; i++)
    {
        char op = getchar();
        while (op != 'I' && op != 'D' && op != 'L' && op != 'R' && op != 'Q')
        {
            op = getchar();
        }
        if (op == 'I')
        {
            int x = read();
            s1[++pos1] = x;
            sum[pos1] = sum[pos1 - 1] + x;
            ans[pos1] = max(ans[pos1 - 1], sum[pos1]);
        }
        else if (op == 'D')
        {
            pos1--;
        }
        else if (op == 'L')
        {
            s2[++pos2] = s1[pos1--];
        }
        else if (op == 'R')
        {
            s1[++pos1] = s2[pos2--];
            sum[pos1] = sum[pos1 - 1] + s1[pos1];
            ans[pos1] = max(ans[pos1 - 1], sum[pos1]);
        }
        else
        {
            int k = read();
            printf("%d\n", ans[k]);
        }
    }
    return 0;
}
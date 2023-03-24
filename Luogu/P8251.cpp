#include <iostream>
#include <stack>
using namespace std;
#define MX 500005
int a[MX], b[MX], pw[20], anc[MX][20], read();
stack<int> s;
int main()
{
    int n = read(), q = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    for (int i = 1; i <= n; i++)
    {
        b[i] = read();
        while (s.size() && (a[i] == a[s.top()] || b[i] >= b[s.top()]))
        {
            anc[s.top()][0] = i, s.pop();
        }
        s.push(i);
    }
    pw[0] = 1;
    for (int j = 1; j < 20; j++)
    {
        pw[j] = pw[j - 1] * 2;
        for (int i = 1; i <= n; i++)
        {
            anc[i][j] = anc[anc[i][j - 1]][j - 1];
        }
    }
    while (q--)
    {
        int l = read(), r = read(), ans = 1;
        for (int i = 19; i >= 0; i--)
        {
            if (anc[l][i] && anc[l][i] <= r)
            {
                ans += pw[i], l = anc[l][i];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
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
// TAG: 倍增 单调栈
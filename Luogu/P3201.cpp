#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> pos[1000005];
int c[100005], g[1000005]; // g[i]表示颜色i的代表色
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
    for (int i = 1; i <= n; i++)
    {
        c[i] = read(), g[c[i]] = c[i];
        if (c[i - 1] != c[i])
        {
            cnt++;
        }
        pos[c[i]].push_back(i);
    }
    for (int i = 1; i <= m; i++)
    {
        int opt = read();
        if (opt == 1)
        {
            int x = read(), y = read();
            if (x == y)
            {
                continue;
            }
            if (pos[g[x]].size() > pos[g[y]].size())
            {
                swap(g[x], g[y]);
            }
            for (int p : pos[g[x]])
            {
                cnt -= (c[p - 1] == g[y]) + (c[p + 1] == g[y]);
            }
            for (int p : pos[g[x]])
            {
                pos[g[y]].push_back(p), c[p] = g[y];
            }
            pos[g[x]].clear();
        }
        else
        {
            printf("%d\n", cnt);
        }
    }
    return 0;
}
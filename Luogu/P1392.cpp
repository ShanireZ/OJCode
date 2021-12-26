#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int read();
int a[805][805];
vector<int> ans[805];
int main()
{
    int n = read(), m = read(), k = read();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = read();
        }
        sort(a[i] + 1, a[i] + 1 + m);
    }
    for (int j = 1; j <= k; j++)
    {
        ans[1].push_back(a[1][j]);
    }
    for (int i = 2; i <= n; i++)
    {
        for (int t = 0; t < k; t++)
        {
            for (int j = 1; j <= k; j++)
            {
                int x = a[i][j] + ans[i - 1][t];
                auto p = upper_bound(ans[i].begin(), ans[i].end(), x);
                if (ans[i].size() == k) // 如果已经够k个了 优胜劣汰优化下
                {
                    if (p == ans[i].end()) // 后面更大 更不可能是答案
                    {
                        break;
                    }
                    else
                    {
                        ans[i].insert(p, x);
                        ans[i].erase(ans[i].end() - 1);
                    }
                }
                else
                {
                    ans[i].insert(p, x);
                }
            }
        }
    }
    for (int j = 0; j < k; j++)
    {
        printf("%d ", ans[n][j]);
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
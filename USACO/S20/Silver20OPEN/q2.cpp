#include <cstdio>
#include <algorithm>
using namespace std;
int read()
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
int cnt[100005], fav[100005][2], ans[100005];
int dfs(int now, int f)
{
    int add = 0;
    if (cnt[f] == 0)
    {
        cnt[f] = now;
        add++;
    }
    else if (cnt[f] > 0 && now < cnt[f]) //id靠前可以替掉后面的
    {
        int pre = cnt[f];
        cnt[f] = now;
        add += dfs(pre, fav[pre][1]);
    }
    return add;
}
int main()
{
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        fav[i][0] = read(), fav[i][1] = read();
    }
    for (int i = n; i >= 1; i--)
    {
        ans[i] = ans[i + 1];
        ans[i] += dfs(i, fav[i][0]);
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}
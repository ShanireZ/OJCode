#include <algorithm>
#include <iostream>
using namespace std;
int len[5][75005], n, ans = 1e9;
void dfs(int step, int mx, int mn)
{
    if (step == 5)
    {
        ans = min(ans, mx - mn);
        return;
    }
    int pos = lower_bound(len[step] + 1, len[step] + n + 1, mn) - len[step];
    if (pos <= n && len[step][pos] <= mx) // 先找是否有mn~mx范围内的数
    {
        dfs(step + 1, mx, mn);
    }
    else if (pos <= n && len[step][pos] > mx) // 没有的话就找第一个大于mx的数
    {
        dfs(step + 1, len[step][pos], mn);
    }
    pos = upper_bound(len[step] + 1, len[step] + n + 1, mx) - len[step] - 1;
    if (pos >= 1 && len[step][pos] >= mn)
    {
        dfs(step + 1, mx, mn);
    }
    else if (pos >= 1 && len[step][pos] < mn) // 没有的话就找第一个小于mn的数
    {
        dfs(step + 1, mx, len[step][pos]);
    }
}
int main()
{
    cin >> n;
    for (int t = 1; t <= 4; t++)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> len[t][i];
        }
        sort(len[t] + 1, len[t] + n + 1);
    }
    for (int i = 1; i <= n; i++)
    {
        dfs(2, len[1][i], len[1][i]);
    }
    cout << ans << endl;
    return 0;
}
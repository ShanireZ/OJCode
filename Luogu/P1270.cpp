#include <iostream>
using namespace std;
struct Node
{
    int lc, rc, dp[605]; // 在当前位置时间花费
};
Node ns[1005];
int T, pos, root;
void dfs(int &now)
{
    now = ++pos;
    int x, y;
    cin >> x >> y;
    if (y == 0) // 走廊
    {
        dfs(ns[now].lc);
        dfs(ns[now].rc);
        for (int t = x * 2; t <= T; t++)
        {
            for (int l = 0; l <= t - x * 2; l++)
            {
                ns[now].dp[t] = max(ns[now].dp[t], ns[ns[now].lc].dp[l] + ns[ns[now].rc].dp[t - x * 2 - l]);
            }
        }
    }
    else // 展室
    {
        for (int t = x * 2; t <= T; t++)
        {
            if ((t - x * 2) / 5 > y)
            {
                ns[now].dp[t] = ns[now].dp[t - 1];
            }
            else
            {
                ns[now].dp[t] = (t - x * 2) / 5;
            }
        }
    }
}
int main()
{
    cin >> T;
    dfs(root);
    cout << ns[root].dp[T - 1] << endl;
    return 0;
}
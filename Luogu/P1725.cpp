#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;
struct Node
{
    long long id, v;
};
deque<Node> q; // 单调不增队列
long long dp[400005], a[400005], n, l, r, pos, ans = -1e10;
int main()
{
    cin >> n >> l >> r;
    for (int i = 0; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n + r; i++)
    {
        dp[i] = -1e10;
    }
    q.push_back(Node{0, 0});
    for (int i = l; i <= n + r; i++)
    {
        if (q.size() && q.front().id < i - r)
        {
            q.pop_front();
        }
        dp[i] = a[i] + q.front().v;
        if (i > n)
        {
            ans = max(ans, dp[i]);
        }
        pos++;
        while (q.size() && q.back().v <= dp[pos])
        {
            q.pop_back();
        }
        q.push_back(Node{pos, dp[pos]});
    }
    cout << ans << endl;
    return 0;
}
// TAG: DP 动态规划 单调栈
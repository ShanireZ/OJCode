#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
long long n, ans, maxdp, dp[100005], a[100005], b[100005];
vector<int> pos[200005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        pos[b[i] + i].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int x : pos[i])
        {
            maxdp = max(maxdp, dp[x]);
        }
        dp[i] = a[i] + maxdp;
        ans = max(ans, dp[i]);
        if (b[i] == 0) // b[i]==0时,上方的遍历未把dp[i]最终值纳入统计中,需要单独处理
        {
            maxdp = max(maxdp, dp[i]);
        }
    }
    cout << ans << endl;
    return 0;
}
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> to[50005];
int n, dp[50005][2];
void dfs(int now, int from)
{
    dp[now][1] = 1;
    for (int nxt : to[now])
    {
        if (nxt == from)
        {
            continue;
        }
        dfs(nxt, now);
        dp[now][0] += max(dp[nxt][0], dp[nxt][1]);
        dp[now][1] += dp[nxt][0];
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int c1, c2;
        cin >> c1 >> c2;
        to[c1].push_back(c2);
        to[c2].push_back(c1);
    }
    dfs(1, 0);
    cout << max(dp[1][0], dp[1][1]) << endl;
    return 0;
}
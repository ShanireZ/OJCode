#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int dp[1000005], vis[1000005];
queue<int> q;
int main()
{
    int n;
    cin >> n;
    vis[1] = 1, q.push(1);
    while (q.size())
    {
        int x = q.front();
        q.pop();
        int nx = x - 1;
        if (nx >= 1 && nx <= n && vis[nx] == 0)
        {
            vis[nx] = 1, dp[nx] = dp[x] + 1, q.push(nx);
        }
        nx = x + 1;
        if (nx >= 1 && nx <= n && vis[nx] == 0)
        {
            vis[nx] = 1, dp[nx] = dp[x] + 1, q.push(nx);
        }
        nx = x * 2;
        if (nx >= 1 && nx <= n && vis[nx] == 0)
        {
            vis[nx] = 1, dp[nx] = dp[x] + 1, q.push(nx);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
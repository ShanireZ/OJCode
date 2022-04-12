#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n;
long long m, tk[50];
vector<long long> cost[5];
void dfs(int type, int now, long long tot)
{
    if (tot > m)
    {
        return;
    }
    if (now > n * type / 2)
    {
        cost[type].push_back(tot);
        return;
    }
    dfs(type, now + 1, tot + tk[now]);
    dfs(type, now + 1, tot);
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> tk[i];
    }
    dfs(1, 1, 0);
    dfs(2, n / 2 + 1, 0);
    long long ans = 0;
    sort(cost[2].begin(), cost[2].end());
    for (int i = 0; i < cost[1].size(); i++)
    {
        ans += upper_bound(cost[2].begin(), cost[2].end(), m - cost[1][i]) - cost[2].begin();
    }
    cout << ans << endl;
    return 0;
}
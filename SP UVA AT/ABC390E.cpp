#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int dp[5][5005], n, lmt, ans;
vector<pair<int, int>> food[5];
int main()
{
    cin >> n >> lmt;
    for (int i = 1; i <= n; i++)
    {
        int v, a, c;
        cin >> v >> a >> c;
        food[v].emplace_back(make_pair(a, c));
    }
    for (int t = 1; t <= 3; t++)
    {
        for (pair<int, int> f : food[t])
        {
            for (int i = lmt; i >= f.second; i--)
            {
                dp[t][i] = max(dp[t][i], dp[t][i - f.second] + f.first);
            }
        }
    }
    for (int i = 0; i <= lmt; i++)
    {
        for (int j = 0; i + j <= lmt; j++)
        {
            int k = lmt - i - j;
            ans = max(ans, min({dp[1][i], dp[2][j], dp[3][k]}));
        }
    }
    cout << ans << endl;
    return 0;
}
#include <iostream>
using namespace std;
int dp[1005];
int main()
{
    int t, m;
    cin >> t >> m;
    for (int i = 1; i <= m; i++)
    {
        int cost, v;
        cin >> cost >> v;
        for (int j = t; j >= cost; j--)
        {
            dp[j] = max(dp[j], v + dp[j - cost]);
        }
    }
    cout << dp[t] << endl;
    return 0;
}
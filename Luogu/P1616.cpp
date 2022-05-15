#include <iostream>
using namespace std;
long long dp[10000005];
int main()
{
    int t, m;
    cin >> t >> m;
    for (int i = 1; i <= m; i++)
    {
        long long a, b;
        cin >> a >> b;
        for (int j = a; j <= t; j++)
        {
            dp[j] = max(dp[j], dp[j - a] + b);
        }
    }
    cout << dp[t] << endl;
    return 0;
}
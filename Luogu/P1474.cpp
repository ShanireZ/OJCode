#include <iostream>
using namespace std;
long long dp[10005];
int main()
{
    int v, n;
    cin >> v >> n;
    dp[0] = 1;
    for (int i = 1; i <= v; i++)
    {
        int x;
        cin >> x;
        for (int j = x; j <= n; j++)
        {
            dp[j] += dp[j - x];
        }
    }
    cout << dp[n] << endl;
    return 0;
}
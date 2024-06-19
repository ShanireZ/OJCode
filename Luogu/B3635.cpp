#include <algorithm>
#include <iostream>
using namespace std;
int dp[1000005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = i;
    }
    for (int i = 5; i <= n; i++)
    {
        dp[i] = dp[i - 5] + 1;
    }
    for (int i = 11; i <= n; i++)
    {
        dp[i] = min(dp[i], dp[i - 11] + 1);
    }
    cout << dp[n] << endl;
    return 0;
}
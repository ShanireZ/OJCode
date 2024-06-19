#include <algorithm>
#include <iostream>
using namespace std;
int dp[1000005];
int main()
{
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0)
        {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
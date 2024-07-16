#include <algorithm>
#include <iostream>
using namespace std;
int dp[1000005][2], n, h;
int main()
{
    cin >> n >> dp[1][0];
    for (int i = 2; i <= n; i++)
    {
        cin >> h;
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + h;
        dp[i][1] = min(dp[i - 1][0], dp[i - 2][0]);
    }
    cout << min(dp[n][0], dp[n][1]) << endl;
    return 0;
}
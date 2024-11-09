#include <algorithm>
#include <iostream>
using namespace std;
int dp[100005];
int main()
{
    int n;
    cin >> n;
    fill(dp, dp + 100005, 100000);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
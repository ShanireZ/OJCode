#include <algorithm>
#include <iostream>
using namespace std;
int n, dp[1005], a[1005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            dp[i] = max(dp[i], dp[j] + a[i - j]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
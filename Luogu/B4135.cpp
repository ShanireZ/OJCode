#include <algorithm>
#include <iostream>
using namespace std;
long long n, a[100005], dp[100005][2];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = dp[i - 2][0] + a[i] + a[i - 1];
    }
    cout << max(dp[n][0], dp[n][1]) << endl;
    return 0;
}
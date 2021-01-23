#include <iostream>
#include <algorithm>
using namespace std;
int dp[10005], s[10005];
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int maxs = 0;
        for (int j = i; j <= n && j - i + 1 <= k; j++)
        {
            maxs = max(maxs, s[j]);
            dp[j] = max(dp[j], dp[i - 1] + (j - i + 1) * maxs);
        }
    }
    cout << dp[n];
    return 0;
}
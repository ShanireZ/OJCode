#include <algorithm>
#include <iostream>
using namespace std;
long long n, a[2005], dp[2005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i] = 1e18, a[i] += a[i - 1];
        for (int st = i; st >= 1; st--)
        {
            long long lst = a[i] - a[st - 1];
            dp[i] = min(dp[i], dp[st - 1] + lst * lst);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
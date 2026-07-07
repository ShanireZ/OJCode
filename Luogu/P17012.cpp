#include <algorithm>
#include <iostream>
using namespace std;
int dp[1005], n, p;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p;
        for (int j = i; j <= n; j++)
        {
            dp[j] = max(dp[j], dp[j - i] + p);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
#include <iostream>
using namespace std;
int n, m, dp[13000];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int w, d;
        cin >> w >> d;
        for (int j = m; j >= w; j--)
        {
            dp[j] = max(dp[j], dp[j - w] + d);
        }
    }
    cout << dp[m] << endl;
    return 0;
}
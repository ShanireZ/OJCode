#include <algorithm>
#include <iostream>
using namespace std;
int dp[40005];
int main()
{
    int n, W;
    cin >> n >> W;
    for (int i = 1; i <= n; i++)
    {
        int v, w, m;
        cin >> v >> w >> m;
        int base = 1;
        while (m >= base)
        {
            for (int j = W; j >= base * w; j--)
            {
                dp[j] = max(dp[j], dp[j - base * w] + base * v);
            }
            m -= base;
            base *= 2;
        }
        for (int j = W; j >= m * w; j--)
        {
            dp[j] = max(dp[j], dp[j - m * w] + m * v);
        }
    }
    cout << dp[W] << endl;
    return 0;
}
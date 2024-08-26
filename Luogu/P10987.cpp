#include <algorithm>
#include <iostream>
using namespace std;
int dp[1005][1005];
int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        int w;
        cin >> w;
        for (int j = a; j >= 0; j--)
        {
            for (int k = b; k >= 0; k--)
            {
                if (k >= w)
                {
                    dp[j][k] = max(dp[j][k], dp[j][k - w] + w);
                }
                if (j >= w)
                {
                    dp[j][k] = max(dp[j][k], dp[j - w][k] + w);
                }
            }
        }
    }
    cout << dp[a][b] << endl;
    return 0;
}
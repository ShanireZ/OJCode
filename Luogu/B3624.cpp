#include <iostream>
using namespace std;
int main()
{
    int n, l, r, ans = 0, dp[305] = {0};
    cin >> n >> l >> r;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int w;
        cin >> w;
        for (int j = r; j >= w; j--)
        {
            dp[j] += dp[j - w];
        }
    }
    for (int i = l; i <= r; i++)
    {
        ans += dp[i];
    }
    cout << ans << endl;
    return 0;
}
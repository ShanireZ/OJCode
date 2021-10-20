#include <iostream>
using namespace std;
int dp[105], mod = 1000007;
int main()
{
    int n, m, a;
    cin >> n >> m;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) //前i种花
    {
        cin >> a;
        for (int j = m; j >= 1; j--) //当前共j盆花
        {
            int tot = 0;
            for (int k = 0; k <= min(a, j); k++) //枚举加入新花的每一种情况
            {
                tot += dp[j - k];
                tot %= mod;
            }
            dp[j] = tot;
        }
    }
    cout << dp[m] << endl;
    return 0;
}
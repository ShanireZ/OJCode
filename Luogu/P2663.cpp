#include <iostream>
using namespace std;
int dp[55][5005], v[105];
int main()
{
    int n, tot = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        tot += v[i];
    }
    tot /= 2;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = n / 2; j >= 1; j--)
        {
            for (int k = tot; k >= v[i]; k--)
            {
                dp[j][k] = max(dp[j][k], dp[j - 1][k - v[i]]);
            }
        }
    }
    for (int i = tot; i >= 0; i--)
    {
        if (dp[n / 2][i])
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
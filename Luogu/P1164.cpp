#include <iostream>
using namespace std;
int dp[10005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int v;
        cin >> v;
        for (int j = m; j >= v; j--)
        {
            if (v == j)
            {
                dp[j] += 1;
            }
            else
            {
                dp[j] = dp[j] + dp[j - v];
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}

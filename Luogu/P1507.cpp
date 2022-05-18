#include <iostream>
using namespace std;
int dp[405][405];
int main()
{
    int v, m, n;
    cin >> v >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        int vi, mi, ci;
        cin >> vi >> mi >> ci;
        for (int j = v; j >= vi; j--)
        {
            for (int k = m; k >= mi; k--)
            {
                dp[j][k] = max(dp[j][k], dp[j - vi][k - mi] + ci);
            }
        }
    }
    cout << dp[v][m] << endl;
    return 0;
}
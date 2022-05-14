#include <iostream>
using namespace std;
int dp[30005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int v, p;
        cin >> v >> p;
        for (int j = n; j >= v; j--)
        {
            dp[j] = max(dp[j], dp[j - v] + v * p);
        }
    }
    cout << dp[n] << endl;
    return 0;
}

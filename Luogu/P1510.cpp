#include <iostream>
using namespace std;
int dp[10005];
int main()
{
    int v, n, c;
    cin >> v >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        int a, t;
        cin >> a >> t;
        for (int j = c; j >= t; j--)
        {
            dp[j] = max(dp[j], dp[j - t] + a);
        }
    }
    for (int i = 1; i <= c; i++)
    {
        if (dp[i] >= v)
        {
            cout << c - i << endl;
            return 0;
        }
    }
    cout << "Impossible" << endl;
    return 0;
}
#include <iostream>
using namespace std;
int c, h, dp[50005];
int main()
{
    cin >> c >> h;
    for (int i = 1; i <= h; i++)
    {
        int v;
        cin >> v;
        for (int j = c; j >= v; j--)
        {
            dp[j] = max(dp[j], dp[j - v] + v);
        }
    }
    cout << dp[c] << endl;
    return 0;
}
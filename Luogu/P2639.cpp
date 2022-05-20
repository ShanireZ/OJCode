#include <iostream>
using namespace std;
int dp[50000];
int main()
{
    int h, n;
    cin >> h >> n;
    for (int i = 1; i <= n; i++)
    {
        int s;
        cin >> s;
        for (int j = h; j >= s; j--)
        {
            dp[j] = max(dp[j], dp[j - s] + s);
        }
    }
    cout << dp[h] << endl;
    return 0;
}
#include <algorithm>
#include <iostream>
using namespace std;
int dp[300005], n, x, a;
int main()
{
    cin >> n >> x;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        for (int j = 300000; j >= a; j--)
        {
            dp[j] = max(dp[j], dp[j - a]);
        }
    }
    for (int i = x; i <= 300000; i++)
    {
        if (dp[i])
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
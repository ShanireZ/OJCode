#include <cstring>
#include <iostream>
using namespace std;
int dp[2000005];
int main()
{
    int k, n;
    cin >> k >> n;
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        for (int j = x; j <= 2000000; j++)
        {
            dp[j] = min(dp[j], dp[j - x] + 1);
        }
    }
    for (int i = 1; i <= 2000000; i++)
    {
        if (dp[i] > k)
        {
            cout << i - 1 << endl;
            break;
        }
    }
    return 0;
}
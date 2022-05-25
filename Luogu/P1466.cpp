#include <algorithm>
#include <iostream>
using namespace std;
long long dp[1000] = {1};
int main()
{
    int n;
    cin >> n;
    int tot = (1 + n) * n / 2;
    if (tot % 2 == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    tot /= 2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = tot; j >= i; j--)
        {
            dp[j] += dp[j - i];
        }
    }
    cout << dp[tot] / 2 << endl;
    return 0;
}
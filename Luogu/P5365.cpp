#include <iostream>
using namespace std;
long long dp[250005];
int k[150], c[150];
int main()
{
    int n, tot = 0;
    long long m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        tot += c[i] * k[i];
    }
    for (int i = 0; i <= tot; i++)
    {
        dp[i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = tot; j >= c[i]; j--)
        {
            for (int x = 1; x <= k[i] && j >= c[i] * x; x++)
            {
                dp[j] = max(dp[j], dp[j - c[i] * x] * x);
            }
        }
    }
    for (int i = 0; i <= tot; i++)
    {
        if (dp[i] >= m)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
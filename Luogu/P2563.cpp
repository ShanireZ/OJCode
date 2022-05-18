#include <iostream>
using namespace std;
int dp[205];
int main()
{
    for (int i = 2; i <= 200; i++)
    {
        int ok = 1;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                ok = 0;
                break;
            }
        }
        if (ok == 0)
        {
            continue;
        }
        dp[i]++;
        for (int j = i + 1; j <= 200; j++)
        {
            dp[j] += dp[j - i];
        }
    }
    int n;
    while (cin >> n)
    {
        cout << dp[n] << endl;
    }
    return 0;
}
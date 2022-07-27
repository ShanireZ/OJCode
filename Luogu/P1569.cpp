#include <iostream>
using namespace std;
int qz[1005], dp[1005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> qz[i];
        qz[i] += qz[i - 1];
        if (qz[i] < 0)
        {
            continue;
        }
        for (int j = i - 1; j >= 0; j--)
        {
            if (qz[i] - qz[j] >= 0)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    (dp[n]) ? cout << dp[n] << endl : cout << "Impossible" << endl;
    return 0;
}
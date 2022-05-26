#include <iostream>
using namespace std;
int c[15] = {0, 1, 3, 5, 7, 9, 10, 11, 14, 15, 17};
long long dpc[15], dp[100005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= 10; i++)
    {
        int v;
        cin >> v;
        for (int j = i; j <= 10; j++)
        {
            dpc[j] = max(dpc[j], dpc[j - i] + v);
        }
    }
    for (int i = 1; i <= 10; i++)
    {
        dpc[i] -= c[i];
    }
    for (int i = 1; i <= 10; i++)
    {
        for (int j = i; j <= n; j++)
        {
            dp[j] = max(dp[j], dp[j - i] + dpc[i]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
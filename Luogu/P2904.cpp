#include <iostream>
using namespace std;
int t[2505], dp[2505];
int main()
{
    int n, m;
    cin >> n >> m;
    t[0] = m;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        dp[i] = t[i] = t[i - 1] + x;
    }
    for (int i = 2; i <= n; i++) // 每船人数
    {
        for (int j = i; j <= n; j++)
        {
            dp[j] = min(dp[j], dp[j - i] + t[i] + m);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
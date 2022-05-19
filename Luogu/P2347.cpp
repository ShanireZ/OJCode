#include <iostream>
using namespace std;
int a[10] = {0, 1, 2, 3, 5, 10, 20}, dp[1005];
int main()
{
    dp[0] = 1;
    for (int i = 1; i <= 6; i++)
    {
        int x;
        cin >> x;
        for (int j = 1; j <= x; j++)
        {
            for (int k = 1000; k >= j * a[i]; k--)
            {
                dp[k] = max(dp[k], dp[k - a[i]]);
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= 1000; i++)
    {
        cnt += dp[i];
    }
    cout << "Total=" << cnt << endl;
    return 0;
}
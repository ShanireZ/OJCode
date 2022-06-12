#include <iostream>
using namespace std;
int dp[255][255], cnt[255];
char mp[255][255];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> mp[i][j];
            if (mp[i][j] == '1')
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                for (int k = 2; k <= dp[i][j]; k++)
                {
                    cnt[k]++;
                }
            }
        }
    }
    for (int i = 2; cnt[i]; i++)
    {
        cout << i << " " << cnt[i] << endl;
    }
    return 0;
}
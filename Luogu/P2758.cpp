#include <algorithm>
#include <iostream>
using namespace std;
int dp[2005][2005], la, lb;
string a, b;
int main()
{
    cin >> a >> b;
    la = a.size(), lb = b.size();
    a = "x" + a, b = "x" + b;
    for (int i = 1; i <= 2000; i++)
    {
        dp[i][0] = dp[0][i] = i;
    }
    for (int i = 1; i <= la; i++)
    {
        for (int j = 1; j <= lb; j++)
        {
            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (a[i] != b[j]));
        }
    }
    cout << dp[la][lb] << endl;
    return 0;
}
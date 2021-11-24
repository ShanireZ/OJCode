#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dp[2005][2005]; //dp[i][j] s的前i个和t的前j个对齐的最小花费
bool check(char x, char y)
{
    return (x == y) ? 0 : 1;
}
int main()
{
    string s, t;
    cin >> s >> t;
    for (int i = 1; i <= s.size(); i++)
    {
        dp[i][0] = i;
    }
    for (int i = 1; i <= t.size(); i++)
    {
        dp[0][i] = i;
    }
    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = 1; j <= t.size(); j++)
        {
            dp[i][j] = min(dp[i - 1][j - 1] + check(s[i - 1], t[j - 1]), min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
        }
    }
    cout << dp[s.size()][t.size()] << endl;
    return 0;
}
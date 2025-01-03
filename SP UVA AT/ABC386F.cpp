#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<int, int> dp[500005];
int k;
string s, t;
int main()
{
    cin >> k >> s >> t;
    s.insert(0, "#"), t.insert(0, "#");
    int ls = s.size(), lt = t.size();
    if (abs(ls - lt) > k)
    {
        cout << "No" << endl;
        return 0;
    }
    for (int j = 0; j < lt; j++)
    {
        dp[0][j] = (j <= k ? j : 0x3f3f3f3f);
    }
    for (int i = 1; i < ls; i++)
    {
        int st = max(1, i - k), ed = min(i + k, lt - 1);
        dp[i][st - 1] = (i <= k ? i : 0x3f3f3f3f);
        for (int j = st; j <= ed; j++)
        {
            int x = min(dp[i - 1][j - 1] + (s[i] != t[j]), min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
            dp[i][j] = (x <= k ? x : 0x3f3f3f3f);
        }
        dp[i][ed + 1] = 0x3f3f3f3f;
    }
    cout << (dp[ls - 1][lt - 1] <= k ? "Yes" : "No") << endl;
    return 0;
}
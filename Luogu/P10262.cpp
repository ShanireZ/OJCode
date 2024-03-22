#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s;
long long ans, dp[150], now[150];
int main()
{
    ios::sync_with_stdio(false);
    int p, c, sz;
    cin >> p >> s;
    sz = s.size();
    for (int i = 0; i < sz; i++)
    {
        c = s[i] - '0', now[c % p] = 1;
        for (int j = 0; j < p; j++)
        {
            now[(j * 10 + c) % p] += dp[j];
        }
        for (int j = 0; j < p; j++)
        {
            dp[j] = now[j], now[j] = 0;
        }
        ans += dp[0];
    }
    cout << ans << endl;
    return 0;
}
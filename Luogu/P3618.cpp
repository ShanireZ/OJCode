#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int base = 233, same[100005], dp[100005], mod = 1000000007;
string a, b;
int main()
{
    int t;
    cin >> t;
    for (int id = 1; id <= t; id++)
    {
        memset(same, 0, sizeof(same));
        memset(dp, 0, sizeof(dp));
        cin >> a >> b;
        int asz = a.size(), bsz = b.size();
        unsigned long long bh = 0;
        for (int i = 0; i < bsz; i++)
        {
            bh = bh * base + b[i];
        }
        unsigned long long p1 = 1;
        for (int i = 1; i <= bsz; i++)
        {
            p1 = p1 * base;
        }
        unsigned long long ah = 0;
        for (int i = 0; i < asz; i++)
        {
            ah = ah * base + a[i];
            if (i >= bsz)
            {
                ah -= p1 * a[i - bsz];
            }
            if (i >= bsz - 1 && ah == bh)
            {
                same[i] = 1;
            }
        }
        dp[0] = 1;
        for (int i = 1; i <= asz; i++)
        {
            dp[i] = dp[i - 1];
            if (same[i - 1])
            {
                dp[i] = (dp[i] + dp[i - bsz]) % mod;
            }
        }
        cout << "Case #" << id << ": " << dp[asz] << endl;
    }
    return 0;
}
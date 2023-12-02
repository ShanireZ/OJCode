#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define MOD 19930726
#define MX 1000005
long long p[MX], cnt[MX];
string s;
int main()
{
    long long n, k, mid = 0, mx = 0;
    cin >> n >> k >> s;
    for (int i = 0; i < (int)s.size(); i++)
    {
        p[i] = (i < mx ? min(p[2 * mid - i], mx - i) : 1);
        while (i + p[i] < (int)s.size() && i - p[i] >= 0 && s[i + p[i]] == s[i - p[i]])
        {
            p[i]++;
        }
        if (i + p[i] > mx)
        {
            mx = i + p[i], mid = i;
        }
        cnt[p[i] * 2 - 1]++;
    }
    long long ans = 1;
    for (int len = 999999; len >= 1; len -= 2)
    {
        cnt[len] += cnt[len + 2];
        long long t = min(k, cnt[len]), base = len;
        k -= t;
        while (t)
        {
            if (t % 2 == 1)
            {
                ans = ans * base % MOD;
            }
            base = base * base % MOD, t /= 2;
        }
        if (k == 0)
        {
            cout << ans << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
    return 0;
}
// TAG: Manacher 最长回文子串
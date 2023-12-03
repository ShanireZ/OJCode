#include <algorithm>
#include <iostream>
#include <set>
#include <string>
using namespace std;
long long a[10000005], n, cnt, base = 1003, mod = 1e13 + 37;
string s, t;
int main()
{
    cin >> n >> s >> t;
    int lent = t.size(), lens = s.size();
    for (int i = 0; i < lent; i++)
    {
        long long pos = 0, hsh = 0;
        for (int j = i; j < lent && pos < lens; j++)
        {
            hsh = (hsh * base + t[j]) % mod;
            while (pos < lens && s[pos] != t[j])
            {
                pos++;
            }
            if (pos < lens)
            {
                a[++cnt] = hsh, pos++;
            }
        }
    }
    sort(a + 1, a + cnt + 1);
    cnt = unique(a + 1, a + cnt + 1) - (a + 1);
    cout << cnt << endl;
    return 0;
}
// TAG: Hash 枚举 贪心
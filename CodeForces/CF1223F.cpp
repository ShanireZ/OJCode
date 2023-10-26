#include <algorithm>
#include <ctime>
#include <iostream>
#include <map>
#include <random>
using namespace std;
mt19937 rnd(time(0));
map<pair<long long, long long>, int> cnt;
long long hsh[300005], hsh2[300005], s[300005], pos;
int main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= 300000; i++)
    {
        hsh[i] = rnd(), hsh2[i] = rnd();
    }
    while (T--)
    {
        cnt.clear(), cnt[{0, 0}] = 1, pos = 0;
        int n;
        cin >> n;
        long long tot1 = 0, tot2 = 0, ans = 0;
        while (n--)
        {
            int now;
            cin >> now;
            if (pos > 0 && s[pos] == now)
            {
                tot1 ^= hsh[pos] * now, tot2 ^= hsh2[pos] * now;
                pos--;
            }
            else
            {
                s[++pos] = now;
                tot1 ^= hsh[pos] * now, tot2 ^= hsh2[pos] * now;
            }
            ans += cnt[{tot1, tot2}];
            cnt[{tot1, tot2}]++;
        }
        cout << ans << "\n";
    }
    return 0;
}
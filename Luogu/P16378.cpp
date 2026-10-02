#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
map<int, vector<int>> mp;
int n, k, T, pos, ans, cnt[300005], a[300005];
int main()
{
    cin >> n >> k >> T;
    for (int i = 1; i <= n; i++)
    {
        int m, t;
        cin >> m;
        while (m--)
        {
            cin >> t;
            mp[t].push_back(i);
            a[++pos] = t;
        }
    }
    mp[T].push_back(0), mp[0].push_back(0);
    a[++pos] = T, a[++pos] = 0;
    sort(a + 1, a + 1 + pos);
    pos = unique(a + 1, a + 1 + pos) - a - 1;
    int l = 2, r = 1, tot = 0;
    while (l <= pos && r < pos)
    {
        do
        {
            r++;
            for (int x : mp[a[r]])
            {
                tot += (cnt[x] == 0);
                cnt[x]++;
            }
        } while (r < pos && tot <= n - k);
        ans = max(ans, a[r] - a[l - 1]);
        do
        {
            for (int x : mp[a[l]])
            {
                cnt[x]--;
                tot -= (cnt[x] == 0);
            }
            l++;
        } while (l <= pos && tot > n - k);
    }
    cout << ans << endl;
    return 0;
}
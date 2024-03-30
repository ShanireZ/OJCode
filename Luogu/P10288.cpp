#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
map<int, int> mp;
vector<int> rec[100005];
int main()
{
    ios::sync_with_stdio(0);
    int T, n, q, l, r, x, pos;
    scanf("%d", &T);
    while (T--)
    {
        pos = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &x);
            if (mp[x] == 0)
            {
                mp[x] = ++pos;
            }
            rec[mp[x]].emplace_back(i);
        }
        scanf("%d", &q);
        while (q--)
        {
            scanf("%d %d %d", &l, &r, &x);
            x = mp[x];
            l = lower_bound(rec[x].begin(), rec[x].end(), l) - rec[x].begin();
            r = upper_bound(rec[x].begin(), rec[x].end(), r) - rec[x].begin();
            printf("%d\n", r - l);
        }
        for (int i = 1; i <= pos; i++)
        {
            rec[i].clear();
        }
        mp.clear();
    }
    return 0;
}
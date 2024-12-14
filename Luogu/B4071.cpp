#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
multiset<int> cl[1005], all;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int p, c;
        cin >> p >> c;
        cl[p].emplace(c);
    }
    long long ans = 1e18;
    for (int tar = cl[1].size(); tar <= m; tar++)
    {
        all.clear();
        long long res = 0, cnt = cl[1].size();
        for (int i = 2; i <= n; i++)
        {
            int dlt = cl[i].size() - (tar - 1);
            for (auto x : cl[i])
            {
                if (dlt > 0)
                {
                    res += x, cnt++, dlt--;
                }
                else
                {
                    all.emplace(x);
                }
            }
        }
        for (auto x : all)
        {
            if (cnt < tar)
            {
                res += x, cnt++;
            }
            else
            {
                break;
            }
        }
        ans = min(ans, res);
    }
    cout << ans << endl;
    return 0;
}
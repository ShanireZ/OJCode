#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> z[5];
int T, n, ans;
int main()
{
    cin >> T;
    while (T--)
    {
        ans = 0, z[1].clear(), z[2].clear(), z[3].clear();
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int zd = 0, cd = 0, zid = 0, v;
            for (int j = 1; j <= 3; j++)
            {
                cin >> v;
                if (v > zd)
                {
                    cd = zd;
                    zd = v, zid = j;
                }
                else if (v > cd)
                {
                    cd = v;
                }
            }
            ans += zd, z[zid].push_back(zd - cd);
        }
        for (int i = 1; i <= 3; i++)
        {
            sort(z[i].begin(), z[i].end(), greater<int>());
            while ((int)z[i].size() > n / 2)
            {
                ans -= z[i].back();
                z[i].pop_back();
            }
        }
        cout << ans << endl;
    }
    return 0;
}
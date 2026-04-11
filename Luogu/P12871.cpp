#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
string s;
int n, ans, mn, mx, base = 233, mod = 1e7 + 19, vis[1005];
map<string, int> mp[1005];
int main()
{
    cin >> n >> mn >> mx;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        if (s.size() < mn)
        {
            mp[i][s] = 1;
        }
        for (int j = mn; j <= mx; j++)
        {
            for (int k = 0; k <= (int)s.size() - j; k++)
            {
                mp[i][s.substr(k, j)] = 1;
            }
        }
    }
    cin >> s;
    if (s.size() < mn)
    {
        for (int i = 1; i <= n; i++)
        {
            ans += mp[i][s];
        }
        cout << ans << endl;
        return 0;
    }
    for (int j = mn; j <= mx; j++)
    {
        for (int k = 0; k <= (int)s.size() - j; k++)
        {
            string now = s.substr(k, j);
            for (int i = 1; i <= n; i++)
            {
                if (mp[i][now])
                {
                    vis[i] = 1;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans += vis[i];
    }
    cout << ans << endl;
    return 0;
}
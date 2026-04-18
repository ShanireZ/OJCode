#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;
int t, n, ok, cd[30];
string s[60005];
map<string, int> vis;
int main()
{
    cin >> t;
    for (int cas = 1; cas <= t; cas++)
    {
        for (int i = 0; i < 26; i++)
        {
            cin >> cd[i];
        }
        cin >> n;
        ok = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> s[i];
            for (int j = 0; j < (int)s[i].size(); j++)
            {
                s[i][j] = cd[s[i][j] - 'A'] + '0';
            }
            if (vis[s[i]] == 1)
            {
                ok = 1;
            }
            vis[s[i]] = 1;
        }
        cout << "Case #" << cas << ": ";
        cout << (ok == 0 ? "NO" : "YES") << endl;
        vis.clear();
    }
    return 0;
}
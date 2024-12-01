#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
int subs[5005][5005], add[5005], ans[100005], k, n;
map<int, long long> mp;
pair<int, long long> res = {0, 0};
int main()
{
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> subs[i][0];
        for (int j = 1; j <= subs[i][0]; j++)
        {
            cin >> subs[i][j];
        }
        cin >> add[i];
    }
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ans[i];
    }
    for (int i = 1; i <= k; i++)
    {
        int ok = 1, keys = ans[subs[i][1]];
        for (int j = 1; j <= subs[i][0]; j++)
        {
            if (ans[subs[i][j]] != keys)
            {
                ok = 0;
                break;
            }
        }
        mp[keys] += ok * add[i];
        if (mp[keys] > res.second)
        {
            res = {keys, mp[keys]};
        }
    }
    cout << res.second << endl
         << res.first << endl;
    return 0;
}
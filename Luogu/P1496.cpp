#include <iostream>
#include <algorithm>
using namespace std;
int t[20005][2];
int all[40005];
int status[40005];
int main()
{
    int n, p = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i][0] >> t[i][1];
        all[p++] = t[i][0];
        all[p++] = t[i][1];
    }
    sort(all, all + p);
    p = unique(all, all + p) - all;
    for (int i = 1; i <= n; i++)
    {
        t[i][0] = lower_bound(all, all + p, t[i][0]) - all;
        t[i][1] = lower_bound(all, all + p, t[i][1]) - all;
        status[t[i][0]]++;
        status[t[i][1]]--;
    }
    int sign = 0, ans = 0;
    for (int i = 0; i < p; i++)
    {
        sign += status[i];
        if(sign > 0)
        {
            ans += all[i + 1] - all[i];
        }
    }
    cout << ans;
    return 0;
}
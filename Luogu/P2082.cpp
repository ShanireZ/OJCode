#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<long long> all;
int cf[200005], rd[100005][2];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        long long s, t;
        cin >> s >> t;
        rd[i][0] = s, rd[i][1] = t;
        all.push_back(s), all.push_back(t);
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    for (int i = 1; i <= n; i++)
    {
        rd[i][0] = lower_bound(all.begin(), all.end(), rd[i][0]) - all.begin();
        rd[i][1] = lower_bound(all.begin(), all.end(), rd[i][1]) - all.begin();
        cf[rd[i][0]]++, cf[rd[i][1]]--;
    }
    long long flag = 0, tot = 0, ans = 0;
    for (int i = 0; i < 200000; i++)
    {
        tot += cf[i];
        if (flag == 0 && tot)
        {
            flag = 1, ans -= all[i];
        }
        else if (flag == 1 && tot == 0)
        {
            flag = 0, ans += all[i] + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}
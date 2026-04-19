#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
map<int, vector<int>> pos;
set<int> s;
int n, ans, ex, a[200005], b[200005], c0[200005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        int x = b[i] - a[i];
        pos[x].push_back(i), s.insert(x);
        c0[i] = c0[i - 1] + (x == 0);
    }
    ans = pos[0].size();
    for (int x : s)
    {
        if (x == 0)
        {
            continue;
        }
        int now = 0, pre = pos[x][0];
        for (int p : pos[x])
        {
            now = max(1, now + 1 - (c0[p] - c0[pre]));
            pre = p, ex = max(ex, now);
        }
    }
    cout << ans + ex << endl;
    return 0;
}
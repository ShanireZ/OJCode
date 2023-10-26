#include <algorithm>
#include <iostream>
#include <map>
#include <set>
using namespace std;
struct Node
{
    int x, y;
    bool operator<(const Node &oth) const
    {
        return x < oth.x;
    }
};
Node ns[50005];
map<int, int> cnt;
set<int> s;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].x >> ns[i].y;
        s.insert(ns[i].y);
    }
    sort(ns + 1, ns + 1 + n);
    int ans = 0x3f3f3f3f, c = 0, l = 1, r = 0;
    while (r < n)
    {
        while (c != s.size() && r < n)
        {
            r++;
            if (cnt[ns[r].y] == 0)
            {
                c++;
            }
            cnt[ns[r].y]++;
        }
        while (c == s.size())
        {
            ans = min(ans, ns[r].x - ns[l].x);
            cnt[ns[l].y]--;
            if (cnt[ns[l].y] == 0)
            {
                c--;
            }
            l++;
        }
    }
    cout << ans << endl;
    return 0;
}
// TAG: 尺取法 离散化 双指针
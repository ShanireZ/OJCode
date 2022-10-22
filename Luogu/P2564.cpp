#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int p, tp;
    bool operator<(const Node oth) const
    {
        return p < oth.p;
    }
};
Node ns[1000005];
int n, k, pos, t[100];
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        int x;
        cin >> x;
        for (int j = 1; j <= x; j++)
        {
            ns[++pos].tp = i;
            cin >> ns[pos].p;
        }
    }
    sort(ns + 1, ns + 1 + n);
    int l = 1, r = 0, ans = 0x3f3f3f3f, cnt = 0;
    while (r < n)
    {
        while (r < n && cnt < k)
        {
            r++;
            if (t[ns[r].tp]++ == 0)
            {
                cnt++;
            }
        }
        while (l <= r && cnt == k)
        {
            ans = min(ans, ns[r].p - ns[l].p);
            if (--t[ns[l].tp] == 0)
            {
                cnt--;
            }
            l++;
        }
    }
    cout << ans << endl;
    return 0;
}
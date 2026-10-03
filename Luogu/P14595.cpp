#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int l, r;
    bool operator<(const Node &oth) const
    {
        return l < oth.l;
    }
};
Node ns[300005];
int n, k, ans;
priority_queue<int, vector<int>, greater<int>> q;
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].l >> ns[i].r;
    }
    sort(ns + 1, ns + n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (i >= k)
        {
            if (k != 1)
            {
                ans = max(ans, min(ns[i].r, q.top()) - ns[i].l);
            }
            else
            {
                ans = max(ans, ns[i].r - ns[i].l);
            }
        }
        q.push(ns[i].r);
        if (q.size() == k)
        {
            q.pop();
        }
    }
    cout << ans << endl;
    return 0;
}
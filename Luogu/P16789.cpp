#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int t, w, k;
    bool operator<(const Node &oth) const
    {
        return t < oth.t;
    }
};
Node ns[200005];
priority_queue<int, vector<int>, greater<int>> p, s;
long long n, ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].t >> ns[i].w >> ns[i].k;
    }
    sort(ns + 1, ns + n + 1);
    for (int i = 1, now = 0; i <= n; i++)
    {
        if (now < ns[i].t)
        {
            now++, ans += ns[i].w;
            ns[i].k ? s.push(ns[i].w) : p.push(ns[i].w);
        }
        else
        {
            if (p.size() && (p.top() < ns[i].w || ns[i].k))
            {
                ans += ns[i].w - p.top();
                p.pop();
                ns[i].k ? s.push(ns[i].w) : p.push(ns[i].w);
            }
            else if (ns[i].k && s.size() && s.top() < ns[i].w)
            {
                ans += ns[i].w - s.top();
                s.pop();
                s.push(ns[i].w);
            }
        }
    }
    cout << s.size() << " " << ans << endl;
    return 0;
}
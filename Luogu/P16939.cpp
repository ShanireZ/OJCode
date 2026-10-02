#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int w, s, t;
};
Node ns[200005];
priority_queue<long long> q;
int n, ans;
bool cmp(Node a, Node b)
{
    return a.t < b.t;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].w >> ns[i].s >> ns[i].t;
    }
    sort(ns + 1, ns + 1 + n, cmp);
    long long tot = 0;
    for (int i = 1; i <= n; i++)
    {
        tot += ns[i].w - ns[i].s;
        q.push(ns[i].w - ns[i].s);
        while (tot > 0)
        {
            tot -= q.top();
            q.pop(), ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
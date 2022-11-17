#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
struct Cow
{
    int p, c;
    bool operator<(const Cow &oth) const
    {
        return c < oth.c;
    }
};
Cow cs[50005];
struct Value
{
    int id, val;
    bool operator<(const Value &oth) const
    {
        return val > oth.val;
    }
};
priority_queue<Value> p, c;
priority_queue<int, vector<int>, greater<int>> dif;
int vis[50005], n, k;
long long m, tot;
int main()
{
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> cs[i].p >> cs[i].c;
    }
    sort(cs + 1, cs + 1 + n);
    for (int i = 1; i <= k; i++)
    {
        tot += cs[i].c, dif.push(cs[i].p - cs[i].c);
        if (tot > m)
        {
            cout << i - 1 << endl;
            return 0;
        }
    }
    for (int i = k + 1; i <= n; i++)
    {
        p.push(Value{i, cs[i].p}), c.push(Value{i, cs[i].c});
    }
    for (int i = k + 1; i <= n; i++)
    {
        while (vis[p.top().id])
        {
            p.pop();
        }
        while (vis[c.top().id])
        {
            c.pop();
        }
        int id1 = c.top().id, cost1 = c.top().val + dif.top();
        int id2 = p.top().id, cost2 = p.top().val;
        if (cost1 < cost2)
        {
            tot += cost1, vis[id1] = 1;
            c.pop(), dif.pop(), dif.push(cs[id1].p - cs[id1].c);
        }
        else
        {
            tot += cost2, vis[id2] = 1;
            p.pop();
        }
        if (tot > m)
        {
            cout << i - 1 << endl;
            return 0;
        }
    }
    cout << n << endl;
    return 0;
}
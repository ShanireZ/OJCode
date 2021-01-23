#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <climits>
#include <set>
using namespace std;
int n, m, pos, gpos, mod = 1e9 + 7;
struct Node
{
    int dfn, low, cost, in;
    vector<int> to;
};
Node ns[100005];
multiset<int> g[100005];
stack<int> stk;
void tarjan(int now)
{
    ns[now].dfn = ns[now].low = ++pos;
    ns[now].in = 1;
    stk.push(now);
    for (int i = 0; i < ns[now].to.size(); i++)
    {
        int to = ns[now].to[i];
        if (ns[to].dfn == 0)
        {
            tarjan(to);
            ns[now].low = min(ns[now].low, ns[to].low);
        }
        else if (ns[to].in)
        {
            ns[now].low = min(ns[now].low, ns[to].dfn);
        }
    }
    if (ns[now].dfn == ns[now].low)
    {
        int id;
        gpos++;
        do
        {
            id = stk.top();
            ns[id].in = 0;
            stk.pop();
            g[gpos].insert(ns[id].cost);
        } while (id != now);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].cost;
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        ns[a].to.push_back(b);
    }
    for (int i = 1; i <= n; i++)
    {
        if (ns[i].dfn == 0)
        {
            tarjan(i);
        }
    }
    long long minc = 0, cnt = 1;
    for (int i = 1; i <= gpos; i++)
    {
        minc = minc + *g[i].begin();
        cnt = cnt * g[i].count(*g[i].begin()) % mod;
    }
    cout << minc << " " << cnt;
    return 0;
}
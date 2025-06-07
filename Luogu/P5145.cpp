#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MX 100005
int n, npos, gpos, ans, dfn[MX], low[MX], g[MX], val[MX];
pair<int, int> to[MX];
vector<int> pt;
void tarjan(int now)
{
    dfn[now] = low[now] = ++npos;
    pt.push_back(now);
    int nxt = to[now].first;
    if (dfn[nxt] == 0)
    {
        tarjan(nxt);
        low[now] = min(low[now], low[nxt]);
    }
    else if (g[nxt] == 0)
    {
        low[now] = min(low[now], dfn[nxt]);
    }
    if (low[now] == dfn[now])
    {
        gpos++;
        while (pt.back() != now)
        {
            val[gpos] += to[pt.back()].second;
            pt.pop_back();
        }
        val[gpos] += to[pt.back()].second;
        pt.pop_back();
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> to[i].first >> to[i].second;
    }
    for (int i = 1; i <= n; i++)
    {
        if (dfn[i] == 0)
        {
            tarjan(i);
        }
    }
    for (int i = 1; i <= gpos; i++)
    {
        ans = max(ans, val[i]);
    }
    cout << ans << endl;
    return 0;
}
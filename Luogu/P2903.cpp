#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Node
{
    int x, y, r;
};
Node ns[1100];
vector<int> es[1100];
int n, fx, fy, fid, sid, ok;
void dfs(int now, int from, double v, double tot)
{
    tot += v;
    if (now == fid)
    {
        ok = 1;
        cout << (long long)tot << endl;
        return;
    }
    for (int nxt : es[now])
    {
        if (nxt == from)
        {
            continue;
        }
        dfs(nxt, now, 1.0 * v * ns[now].r / ns[nxt].r, tot);
        if (ok)
        {
            return;
        }
    }
    tot -= v;
}
int main()
{
    cin >> n >> fx >> fy;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].x >> ns[i].y >> ns[i].r;
        if (ns[i].x == 0 && ns[i].y == 0)
        {
            sid = i;
        }
        else if (ns[i].x == fx && ns[i].y == fy)
        {
            fid = i;
        }
        for (int j = 1; j < i; j++)
        {
            if ((ns[i].x - ns[j].x) * (ns[i].x - ns[j].x) + (ns[i].y - ns[j].y) * (ns[i].y - ns[j].y) <= (ns[i].r + ns[j].r) * (ns[i].r + ns[j].r))
            {
                es[i].push_back(j), es[j].push_back(i);
            }
        }
    }
    dfs(sid, 0, 10000, 0);
    return 0;
}
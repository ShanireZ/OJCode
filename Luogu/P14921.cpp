#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Path
{
    int v, w;
    bool operator<(const Path &oth) const
    {
        return w > oth.w;
    }
};
int n, m, pos = 1, res[2005], d[2005];
vector<int> to[2005];
priority_queue<Path> q;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v), to[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        memset(d, 0x3f, sizeof(d));
        d[i] = 0, q.push(Path{i, 0});
        while (q.size())
        {
            int now = q.top().v, w = q.top().w;
            q.pop();
            if (d[now] == w)
            {
                res[i] = max(res[i], w);
                for (int nxt : to[now])
                {
                    if (d[nxt] > w + 1)
                    {
                        d[nxt] = w + 1;
                        q.push(Path{nxt, d[nxt]});
                    }
                }
            }
        }
        if (res[pos] > res[i])
        {
            pos = i;
        }
    }
    cout << pos << endl;
    return 0;
}
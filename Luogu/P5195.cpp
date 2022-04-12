#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
struct Path
{
    int t, w;
    bool operator<(const Path np) const
    {
        return w > np.w;
    }
};
priority_queue<Path> p;
struct Edge
{
    int to, d, pre;
};
Edge es[9000005];
int w, h, st, ed, pos, m[1000005], dis[2000005], last[2000005];
int f[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int make_id(int x, int y)
{
    return y + (x - 1) * w;
}
void dijkstra()
{
    memset(dis, 0x3f, sizeof(dis));
    p.push({st, 0});
    while (p.size())
    {
        int now = p.top().t, d = p.top().w;
        p.pop();
        if (dis[now] != 0x3f3f3f3f)
        {
            continue;
        }
        dis[now] = d;
        for (int i = last[now]; i != 0; i = es[i].pre)
        {
            int to = es[i].to, nd = es[i].d;
            if (dis[to] > d + nd)
            {
                p.push({to, d + nd});
            }
        }
    }
}
int main()
{
    cin >> w >> h;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            int id = make_id(i, j);
            cin >> m[id];
        }
    }
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            int id = make_id(i, j);
            if (m[id] == 1)
            {
                continue;
            }
            else if (m[id] == 2)
            {
                st = id;
            }
            else if (m[id] == 3)
            {
                ed = id;
            }
            else if (m[id] == 4)
            {
                es[++pos] = {id + w * h, 0, last[id]};
                last[id] = pos;
            }
            for (int k = 0; k < 4; k++)
            {
                int ni = i + f[k][0], nj = j + f[k][1];
                int nid = make_id(ni, nj);
                if (ni < 1 || nj < 1 || ni > h || nj > w || m[nid] == 1)
                {
                    continue;
                }
                es[++pos] = {nid + w * h, 1, last[id + w * h]};
                last[id + w * h] = pos;
                if (m[nid] != 3)
                {
                    es[++pos] = {nid, 1, last[id]};
                    last[id] = pos;
                }
            }
        }
    }
    dijkstra();
    cout << dis[ed + w * h] << endl;
    return 0;
}
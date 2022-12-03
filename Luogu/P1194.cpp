#include <algorithm>
#include <iostream>
using namespace std;
struct Edge
{
    int x, y, z;
    bool operator<(const Edge oth) const
    {
        return z < oth.z;
    }
};
Edge es[300000];
int g[505];
int find(int x)
{
    if (x != g[x])
    {
        g[x] = find(g[x]);
    }
    return g[x];
}
int main()
{
    int a, b, pos = 0, tot = 0;
    cin >> a >> b;
    for (int i = 1; i <= b; i++)
    {
        g[i] = i, pos++;
        es[pos].x = 0, es[pos].y = i, es[pos].z = a;
        for (int j = 1; j <= b; j++)
        {
            int w;
            cin >> w;
            if (w != 0)
            {
                pos++;
                es[pos].x = i, es[pos].y = j, es[pos].z = w;
            }
        }
    }
    sort(es + 1, es + 1 + pos);
    for (int i = 1; i <= pos; i++)
    {
        int gx = find(es[i].x), gy = find(es[i].y);
        if (gx != gy)
        {
            g[gx] = gy, tot += es[i].z;
        }
    }
    cout << tot << endl;
    return 0;
}
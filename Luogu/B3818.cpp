#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int minm = 10000, minf = 10000, maxm, maxf;
};
Node h[505], l[505];
struct Rab
{
    int x, y;
};
vector<Rab> rm, rf;
int main()
{
    int r, c, n, m, cnt = 0;
    cin >> r >> c >> n >> m;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            char ch;
            cin >> ch;
            if (ch == 'M')
            {
                rm.push_back(Rab{i, j});
                h[i].minm = min(h[i].minm, j), h[i].maxm = max(h[i].maxm, j);
                l[j].minm = min(l[j].minm, i), l[j].maxm = max(l[j].maxm, i);
            }
            else if (ch == 'F')
            {
                rf.push_back(Rab{i, j});
                h[i].minf = min(h[i].minf, j), h[i].maxf = max(h[i].maxf, j);
                l[j].minf = min(l[j].minf, i), l[j].maxf = max(l[j].maxf, i);
            }
        }
    }
    for (Rab rab : rm)
    {
        int x = rab.x, y = rab.y;
        if ((y < h[x].minf) + (y > h[x].maxf) + (x < l[y].minf) + (x > l[y].maxf) >= 3)
        {
            cnt++;
        }
    }
    for (Rab rab : rf)
    {
        int x = rab.x, y = rab.y;
        if ((y < h[x].minm) + (y > h[x].maxm) + (x < l[y].minm) + (x > l[y].maxm) >= 3)
        {
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
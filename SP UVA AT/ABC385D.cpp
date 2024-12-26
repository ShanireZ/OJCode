#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    long long x, y;
};
Node hs[200005], step[200005];
vector<long long> ax, ay, xz[400005], yz[400005];
string fw = "UDLR";
long long n, m, x, y, cnt, ms[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int main()
{
    cin >> n >> m >> x >> y;
    for (int i = 1; i <= n; i++)
    {
        cin >> hs[i].x >> hs[i].y;
        ax.push_back(hs[i].x), ay.push_back(hs[i].y);
    }
    step[0] = {x, y};
    for (int i = 1; i <= m; i++)
    {
        char c;
        int len;
        cin >> c >> len;
        c = fw.find(c);
        long long nx = x + ms[c][0] * len, ny = y + ms[c][1] * len;
        ax.push_back(nx), ay.push_back(ny);
        step[i] = {nx, ny}, x = nx, y = ny;
    }
    sort(ax.begin(), ax.end()), sort(ay.begin(), ay.end());
    ax.erase(unique(ax.begin(), ax.end()), ax.end());
    ay.erase(unique(ay.begin(), ay.end()), ay.end());
    for (int i = 1; i <= n; i++)
    {
        hs[i].x = lower_bound(ax.begin(), ax.end(), hs[i].x) - ax.begin();
        hs[i].y = lower_bound(ay.begin(), ay.end(), hs[i].y) - ay.begin();
        xz[hs[i].x].push_back(hs[i].y), yz[hs[i].y].push_back(hs[i].x);
    }
    for (int i = 0; i < (int)ax.size(); i++)
    {
        sort(xz[i].begin(), xz[i].end());
    }
    for (int i = 0; i < (int)ay.size(); i++)
    {
        sort(yz[i].begin(), yz[i].end());
    }
    x = lower_bound(ax.begin(), ax.end(), step[0].x) - ax.begin();
    y = lower_bound(ay.begin(), ay.end(), step[0].y) - ay.begin();
    for (int i = 1; i <= m; i++)
    {
        step[i].x = lower_bound(ax.begin(), ax.end(), step[i].x) - ax.begin();
        step[i].y = lower_bound(ay.begin(), ay.end(), step[i].y) - ay.begin();
        long long lx = min(x, step[i].x), rx = max(x, step[i].x);
        long long ly = min(y, step[i].y), ry = max(y, step[i].y);
        if (lx == rx) // y轴移动
        {
            auto pl = lower_bound(xz[x].begin(), xz[x].end(), ly);
            auto pr = upper_bound(xz[x].begin(), xz[x].end(), ry);
            for (auto it = pl; it != pr; it++)
            {
                yz[*it].erase(lower_bound(yz[*it].begin(), yz[*it].end(), x));
            }
            cnt += pr - pl, xz[x].erase(pl, pr);
        }
        else // x轴移动
        {
            auto pl = lower_bound(yz[y].begin(), yz[y].end(), lx);
            auto pr = upper_bound(yz[y].begin(), yz[y].end(), rx);
            for (auto it = pl; it != pr; it++)
            {
                xz[*it].erase(lower_bound(xz[*it].begin(), xz[*it].end(), y));
            }
            cnt += pr - pl, yz[y].erase(pl, pr);
        }
        x = step[i].x, y = step[i].y;
    }
    cout << ax[x] << " " << ay[y] << " " << cnt << endl;
    return 0;
}
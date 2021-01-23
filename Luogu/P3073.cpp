#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int sz[250005], g[250005], a[505][505];
int moves[2][2] = {{-1, 0}, {0, -1}};
struct Way
{
    int u, v, w;
};
vector<Way> way;
bool cmp(Way a, Way b)
{
    return a.w < b.w;
}
int dfn(int x)
{
    if (x != g[x])
    {
        g[x] = dfn(g[x]);
    }
    return g[x];
}
int main()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        int x;
        cin >> x;
        cout << x << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            g[(i - 1) * n + j] = (i - 1) * n + j;
            sz[(i - 1) * n + j] = 1;
            cin >> a[i][j];
            for (int k = 0; k < 2; k++)
            {
                int nx = i + moves[k][0];
                int ny = j + moves[k][1];
                if (nx == 0 || ny == 0)
                {
                    continue;
                }
                Way x;
                x.u = (i - 1) * n + j;
                x.v = (nx - 1) * n + ny;
                x.w = abs(a[i][j] - a[nx][ny]);
                way.push_back(x);
            }
        }
    }
    sort(way.begin(), way.end(), cmp);
    int maxn = (n * n + 1) / 2;
    for (int i = 0; i < way.size(); i++)
    {
        int ga = dfn(way[i].u);
        int gb = dfn(way[i].v);
        if (ga != gb)
        {
            g[ga] = gb;
            sz[gb] += sz[ga];
            if (sz[gb] >= maxn)
            {
                cout << way[i].w << endl;
                break;
            }
        }
    }
    return 0;
}
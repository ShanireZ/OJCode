#include <iostream>
#include <algorithm>
using namespace std;
int g[10005];
int ufind(int x)
{
    if (g[x] == x)
    {
        return x;
    }
    return g[x] = ufind(g[x]);
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        g[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int z, x, y;
        cin >> z >> x >> y;
        int gx = ufind(x);
        int gy = ufind(y);
        if (z == 1)
        {
            g[gx] = g[gy];
        }
        else
        {
            if (gx == gy)
            {
                cout << "Y" << endl;
            }
            else
            {
                cout << "N" << endl;
            }
        }
    }
    return 0;
}
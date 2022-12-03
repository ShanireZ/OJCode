#include <iostream>
using namespace std;
int g[1005];
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
    int n, m;
    cin >> n;
    while (n != 0)
    {
        for (int i = 1; i <= n; i++)
        {
            g[i] = i;
        }
        cin >> m;
        int cnt = 0;
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            cin >> x >> y;
            int gx = find(x), gy = find(y);
            if (gx != gy)
            {
                g[gx] = gy, cnt++;
            }
        }
        cout << n - 1 - cnt << endl;
        cin >> n;
    }
}
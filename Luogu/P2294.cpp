#include <iostream>
using namespace std;
int g[105], r[105];
int dfn(int x)
{
    if (x != g[x])
    {
        int fx = g[x];
        g[x] = dfn(g[x]);
        r[x] = r[x] + r[fx];
    }
    return g[x];
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m, trig = 1;
        cin >> n >> m;
        for (int i = 0; i <= n; i++)
        {
            g[i] = i, r[i] = 0;
        }
        while (m--)
        {
            int s, t, v;
            cin >> s >> t >> v;
            s--;
            int gs = dfn(s), gt = dfn(t);
            if (gs == gt && r[s] + v != r[t])
            {
                trig = 0;
            }
            else if (gs != gt)
            {
                r[gt] = r[s] + v - r[t], g[gt] = gs;
            }
        }
        cout << (trig ? "true" : "false") << '\n';
    }
    return 0;
}
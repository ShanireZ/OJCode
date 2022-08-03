#include <iostream>
using namespace std;
int n, m, p, q, col[1000005], g[1000005];
pair<int, int> trans(int x)
{
    int a = (x * p + q) % n + 1, b = (x * q + p) % n + 1;
    if (a > b)
    {
        swap(a, b);
    }
    return make_pair(a, b);
}
int dfn(int now) { return (now == g[now]) ? now : g[now] = dfn(g[now]); }
int main()
{
    cin >> n >> m >> p >> q;
    for (int i = 1; i <= n + 1; i++)
    {
        g[i] = i;
    }
    for (int i = m; i >= 1; i--)
    {
        pair<int, int> rng = trans(i);
        for (int j = rng.first; j <= rng.second;)
        {
            if (j == dfn(j))
            {
                g[j] = j + 1;
                col[j] = i;
            }
            j = dfn(j);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << col[i] << endl;
    }
    return 0;
}
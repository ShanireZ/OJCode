#include <algorithm>
#include <iostream>
using namespace std;
int fa[200005], v[200005], n, k;
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        fa[y] = x;
    }
    for (int i = 1; i <= k; i++)
    {
        int opt, u, a;
        cin >> opt >> u;
        if (opt == 1)
        {
            int f = fa[u];
            while (f != 0 && __gcd(v[f], v[u]) == 1)
            {
                f = fa[f];
            }
            cout << (f == 0 ? -1 : f) << endl;
        }
        else
        {
            cin >> a;
            v[u] = a;
        }
    }
    return 0;
}
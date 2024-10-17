#include <algorithm>
#include <iostream>
using namespace std;
int n, m, t, h[305][305];
int main()
{
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
    {
        fill(h[i], h[i] + 305, 0x3f3f3f3f);
        h[i][i] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        h[a][b] = min(h[a][b], c);
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                h[i][j] = min(h[i][j], max(h[i][k], h[k][j]));
            }
        }
    }
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << (h[a][b] == 0x3f3f3f3f ? -1 : h[a][b]) << '\n';
    }
    return 0;
}
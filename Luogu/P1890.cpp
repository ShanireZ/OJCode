#include <algorithm>
#include <iostream>
using namespace std;
int g[1005][1005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> g[i][i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            g[i][j] = __gcd(g[i][j - 1], g[j][j]);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << g[a][b] << "\n";
    }
    return 0;
}
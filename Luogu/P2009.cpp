#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int n, m, st, ed, w[25][25];
int main()
{
    cin >> n >> m;
    memset(w, -1, sizeof(w));
    for (int i = 1; i <= n; i++)
    {
        int u = i, v = (i == n ? 1 : i + 1), x;
        cin >> x;
        w[u][v] = w[v][u] = x, w[i][i] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        char a, b;
        int x;
        cin >> a >> b >> x;
        int u = a - 'A' + 1, v = b - 'A' + 1;
        w[u][v] = max(x, w[u][v]), w[v][u] = max(x, w[v][u]);
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (w[i][k] != -1 && w[k][j] != -1)
                {
                    if (w[i][j] == -1)
                    {
                        w[i][j] = w[i][k] + w[k][j];
                    }
                    else
                    {
                        w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
                    }
                }
            }
        }
    }
    char a, b;
    cin >> a >> b;
    st = a - 'A' + 1, ed = b - 'A' + 1;
    cout << w[st][ed] << endl;
    return 0;
}
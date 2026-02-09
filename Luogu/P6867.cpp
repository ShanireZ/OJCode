#include <algorithm>
#include <iostream>
using namespace std;
long long n, k, len, a[505][505], vis[505][505];
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    int u = 1, v = 2;
    vis[u][v] = 1;
    for (int i = 2; i <= k; i++)
    {
        int x = a[v][u];
        u = v, v = x;
        if (vis[u][v])
        {
            len = i - vis[u][v];
            k = vis[u][v] + (k - i) % len;
            break;
        }
        vis[u][v] = i;
    }
    u = 1, v = 2;
    for (int i = 2; i <= k; i++)
    {
        int x = a[v][u];
        u = v, v = x;
    }
    cout << u << endl;
    return 0;
}
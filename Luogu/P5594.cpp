#include <algorithm>
#include <iostream>
using namespace std;
int vis[1005][1005];
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int x;
            cin >> x;
            vis[x][j] = 1;
        }
    }
    for (int i = 1; i <= k; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= m; j++)
        {
            cnt += vis[i][j];
        }
        cout << cnt << " ";
    }
    return 0;
}
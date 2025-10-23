#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int n, m, q, cnt, a[3005], vis[3005];
int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> m;
        memset(vis, 0, sizeof(vis)), cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            int x = a[j] % m;
            if (vis[x] == 0)
            {
                vis[x] = 1, cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
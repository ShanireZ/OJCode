#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int ans[1005][1005], vis[5005], n, m, cnt;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> ans[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int l, x, ok = 1;
        cin >> l;
        memset(vis, 0, sizeof(vis));
        for (int j = 1; j <= l; j++)
        {
            cin >> x;
            vis[x] = 1;
        }
        for (int j = 1; j <= m; j++)
        {
            if (vis[ans[i][j]] == 0)
            {
                ok = 0;
                break;
            }
        }
        cnt += ok * 2;
    }
    cout << cnt << endl;
    return 0;
}
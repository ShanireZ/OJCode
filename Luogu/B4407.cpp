#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int T, n, m, x, c, same, v[305][305], mx[305], mn[305];
int main()
{
    cin >> T;
    while (T--)
    {
        memset(mx, 0, sizeof(mx)), memset(mn, 0x3f, sizeof(mn));
        cin >> n >> m >> x;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> v[i][j];
                if (x != i)
                {
                    mx[j] = max(mx[j], v[i][j]);
                    mn[j] = min(mn[j], v[i][j]);
                }
            }
        }
        cin >> c;
        if (n == 1)
        {
            cout << "up" << endl;
            continue;
        }
        for (int j = 1; j <= m; j++)
        {
            if (v[x][j] >= mx[j] || v[x][j] <= mn[j])
            {
                c = (mx[j] - mn[j] > 1 ? c - 1 : -1);
            }
        }
        cout << (c >= 0 ? "down" : "up") << endl;
    }
    return 0;
}
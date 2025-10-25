#include <algorithm>
#include <iostream>
using namespace std;
int n, m, q, a[105][105], ms[5][2] = {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int main()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    while (q--)
    {
        int x, y, ans = 0;
        cin >> x >> y;
        while (ans < n * m)
        {
            int op = a[x][y];
            x += ms[op][0], y += ms[op][1], ans++;
            if (x < 1 || y < 1 || x > n || y > m)
            {
                break;
            }
        }
        cout << (ans < n * m ? ans : -1) << endl;
    }
    return 0;
}
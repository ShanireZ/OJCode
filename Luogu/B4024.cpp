#include <algorithm>
#include <iostream>
using namespace std;
int rec[105][105][55];
int main()
{
    int n, m, k, t;
    cin >> n >> m >> k >> t;
    while (t--)
    {
        int a, x, y;
        cin >> a >> x >> y;
        if (rec[x][y][0] == k)
        {
            int mn = 1e9 + 7, pos = -1;
            for (int i = k; i >= 1; i--)
            {
                if (mn > rec[x][y][i])
                {
                    mn = rec[x][y][i], pos = i;
                }
            }
            for (int i = pos; i < k; i++)
            {
                rec[x][y][i] = rec[x][y][i + 1];
            }
            rec[x][y][k] = a;
            cout << mn << ' ' << k - pos << '\n';
        }
        else
        {
            rec[x][y][++rec[x][y][0]] = a;
            cout << "-1\n";
        }
    }
    return 0;
}
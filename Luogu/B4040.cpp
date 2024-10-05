#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int a[105][105], z[5][5] = {{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, res = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                char c;
                cin >> c;
                a[i][j] = c - '0';
            }
        }
        for (int i = 1; i + 3 <= n && !res; i++)
        {
            for (int j = 1; j + 3 <= m && !res; j++)
            {
                int ok = 1;
                for (int x = 0; x < 4 && ok; x++)
                {
                    for (int y = 0; y < 4 && ok; y++)
                    {
                        ok = (a[i + x][j + y] == z[x][y]);
                    }
                }
                res = max(res, ok);
            }
        }
        cout << (res ? "Yes" : "No") << endl;
    }
    return 0;
}
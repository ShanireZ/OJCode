#include <algorithm>
#include <iostream>
using namespace std;
char mp[1005][1005];
int main()
{
    int n, m, a = 1000, b = 1, c = 1000, d = 1;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mp[i][j];
            if (mp[i][j] == '#')
            {
                a = min(a, i), b = max(b, i);
                c = min(c, j), d = max(d, j);
            }
        }
    }
    for (int i = a; i <= b; i++)
    {
        for (int j = c; j <= d; j++)
        {
            if (mp[i][j] == '.')
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
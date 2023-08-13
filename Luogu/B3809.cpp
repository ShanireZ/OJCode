#include <algorithm>
#include <iostream>
using namespace std;
int l[205], h[205], fs[205][205];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int x;
            cin >> x;
            fs[m - j + 1][i] = x;
            l[i] += x, h[m - j + 1] += x;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << bool(l[i]) << " ";
    }
    cout << "\n";
    for (int i = 1; i <= m; i++)
    {
        cout << bool(h[i]) << " ";
    }
    cout << "\n";
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << fs[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
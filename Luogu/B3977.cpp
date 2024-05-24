#include <algorithm>
#include <iostream>
using namespace std;
int a[1005][1005], h[1005], l[1005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
        h[i] = l[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1)
        {
            swap(h[x], h[y]);
        }
        else
        {
            swap(l[x], l[y]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[h[i]][l[j]] << " ";
        }
        cout << endl;
    }
    return 0;
}
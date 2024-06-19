#include <algorithm>
#include <iostream>
using namespace std;
int a[1005][1005], h[1005], l[1005];
int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char ch;
            cin >> ch;
            a[i][j] = ch - '0';
            l[j] = j;
        }
        h[i] = i;
    }
    while (q--)
    {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1)
        {
            swap(h[x], h[y]);
        }
        else if (op == 2)
        {
            swap(l[x], l[y]);
        }
        else
        {
            cout << a[h[x]][l[y]] << endl;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << a[h[i]][l[j]];
        }
        cout << endl;
    }
    return 0;
}
#include <algorithm>
#include <iostream>
using namespace std;
int a[100], b[100];
int main()
{
    int n, m, sz = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        sz += (a[x] == 0);
        a[x] = 1;
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        b[x] = 1;
    }
    cout << sz << endl;
    for (int i = 0; i <= 63; i++)
    {
        if (a[i] && b[i])
        {
            cout << i << " ";
        }
    }
    cout << endl;
    for (int i = 0; i <= 63; i++)
    {
        if (a[i] || b[i])
        {
            cout << i << " ";
        }
    }
    return 0;
}
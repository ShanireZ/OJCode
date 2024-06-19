#include <algorithm>
#include <iostream>
using namespace std;
int a[1005];
int main()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int x;
        cin >> x;
        a[x] = 1 - a[x];
        x + 1 <= n ? a[x + 1] = 1 - a[x + 1] : a[1] = 1 - a[1];
        x - 1 >= 1 ? a[x - 1] = 1 - a[x - 1] : a[n] = 1 - a[n];
    }
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[1005] = {0};
    int zd = -1, zx = 2000;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] > zd)
        {
            zd = a[i];
        }
        if (a[i] < zx)
        {
            zx = a[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        a[i] = 100.0 * (a[i] - zx) / (zd - zx);
        cout << a[i] << " ";
    }
    return 0;
}
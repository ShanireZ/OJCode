#include <algorithm>
#include <iostream>
using namespace std;
int a[105];
int main()
{
    int n, zd = -1e8, tot = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] > zd)
        {
            zd = a[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != zd)
        {
            tot = tot + a[i];
        }
    }
    cout << tot << endl;
    return 0;
}
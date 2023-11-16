#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int a[105], n, m, c = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == m)
        {
            c++;
        }
    }
    cout << c << endl;
    return 0;
}
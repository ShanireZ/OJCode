#include <algorithm>
#include <iostream>
using namespace std;
int a[15], n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int t = n - 1; t >= 1; t--)
    {
        for (int i = 1; i <= t; i++)
        {
            a[i] = a[i] + a[i + 1];
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
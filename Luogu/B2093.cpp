#include <algorithm>
#include <iostream>
using namespace std;
int a[10005];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n - 1; i++)
    {
        cin >> a[i];
    }
    int x;
    cin >> x;
    for (int i = 0; i <= n - 1; i++)
    {
        if (a[i] == x)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
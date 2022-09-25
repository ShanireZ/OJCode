#include <algorithm>
#include <iostream>
using namespace std;
int a[10];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n);
        n = unique(a + 1, a + 1 + n) - (a + 1);
        if (n > 1 || x / abs(x) == a[1] / abs(a[1]) || abs(x) % abs(a[1]) != 0)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
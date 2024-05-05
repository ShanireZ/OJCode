#include <algorithm>
#include <iostream>
using namespace std;
int a[2005], n, k;
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n, greater<int>());
    for (int i = k + 1; i <= n; i++)
    {
        if (a[i] != a[i - 1])
        {
            cout << i - 1 << endl;
            return 0;
        }
    }
    cout << n << endl;
    return 0;
}
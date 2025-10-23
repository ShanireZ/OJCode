#include <algorithm>
#include <iostream>
using namespace std;
int T, n, ok, a[105];
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        ok = 1;
        for (int i = 1; i <= n; i += 2)
        {
            if (a[i] != a[i + 1])
            {
                ok = 0;
                break;
            }
        }
        for (int i = 2; i < n; i += 2)
        {
            if (a[i] == a[i + 1])
            {
                ok = 0;
                break;
            }
        }
        cout << (ok ? "Yes" : "No") << endl;
    }
    return 0;
}
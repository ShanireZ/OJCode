#include <algorithm>
#include <iostream>
using namespace std;
int a[100005];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, ok = 1;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n);
        for (int i = 1; i <= n; i++)
        {
            if (a[n] % a[i] != 0)
            {
                ok = 0;
                break;
            }
        }
        cout << (ok ? "Yes" : "No") << '\n';
    }
    return 0;
}
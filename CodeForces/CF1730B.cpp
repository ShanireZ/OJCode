#include <iomanip>
#include <iostream>
using namespace std;
int x[100005], t[100005];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> x[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> t[i];
        }
        int l = 0x3f3f3f3f, r = -0x3f3f3f3f;
        for (int i = 1; i <= n; i++)
        {
            l = min(l, x[i] - t[i]);
            r = max(r, x[i] + t[i]);
        }
        cout << fixed << setprecision(6) << (l + r) / 2.0 << "\n";
    }
    return 0;
}
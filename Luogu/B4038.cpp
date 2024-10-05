#include <algorithm>
#include <iostream>
using namespace std;
int sum[10005], t;
int main()
{
    cin >> t;
    while (t--)
    {
        int n, a, ok = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a;
            sum[i] = sum[i - 1] + a;
        }
        for (int i = 1; i <= n && ok == 0; i++)
        {
            ok = (sum[i] * 2 == sum[n]);
        }
        cout << (ok ? "Yes" : "No") << endl;
    }
    return 0;
}
#include <algorithm>
#include <iostream>
using namespace std;
long long T, n, d, x[1005];
int main()
{
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> n >> d;
        for (int i = 1; i <= n; i++)
        {
            cin >> x[i];
        }
        for (int i = n; i >= 1; i--)
        {
            d = d / x[i] * x[i];
        }
        cout << "Case #" << t << ": " << d << endl;
    }
    return 0;
}
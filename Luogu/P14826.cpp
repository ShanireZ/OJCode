#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long n, k;
        cin >> n >> k;
        long long res = k * n;
        for (long long a = 1; a * a <= n; a++)
        {
            long long b = n / a;
            long long c = n - a * b;
            res = min(res, a + b + k * c);
        }
        cout << res << endl;
    }
    return 0;
}
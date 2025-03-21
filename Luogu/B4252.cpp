#include <algorithm>
#include <iostream>
using namespace std;
long long n, res, b, a[1000005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b;
        res += a[i] * b;
    }
    cout << res << endl;
    return 0;
}
#include <algorithm>
#include <iostream>
using namespace std;
int a[100005], n, q;
int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int t = a[2] - a[1];
    for (int i = 3; i <= n; i++)
    {
        t = __gcd(t, a[i] - a[1]);
    }
    for (int i = 1; i <= q; i++)
    {
        int res = __gcd(t, a[1] + i);
        cout << abs(res) << endl;
    }
    return 0;
}
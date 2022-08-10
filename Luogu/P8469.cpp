#include <algorithm>
#include <iostream>
using namespace std;
int a[100005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    long long ans = 1, mod = 1e9 + 7;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * (a[i] / a[1]) % mod;
    }
    cout << a[1] << " " << ans << endl;
    return 0;
}
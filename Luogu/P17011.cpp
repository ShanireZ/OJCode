#include <algorithm>
#include <iostream>
using namespace std;
int n, ans, a[1005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        for (int j = 1; j < i; j++)
        {
            if (__gcd(a[i], a[j]) == 1)
            {
                ans = max(ans, a[i] + a[j]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
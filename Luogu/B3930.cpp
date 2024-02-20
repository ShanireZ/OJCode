#include <algorithm>
#include <iostream>
using namespace std;
int a[1000005], n, ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int ed = max(1, n - 32);
    for (int i = n; i >= ed; i--)
    {
        for (int j = i - 1; j >= ed; j--)
        {
            ans = max(ans, a[i] & a[j]);
        }
    }
    cout << ans << endl;
    return 0;
}
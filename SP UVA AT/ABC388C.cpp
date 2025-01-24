#include <algorithm>
#include <iostream>
using namespace std;
int a[500005], n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    long long ans = 0;
    for (int i = 1, j = 2; i < n; i++)
    {
        while (j <= n && a[i] * 2 > a[j])
        {
            j++;
        }
        ans += n - j + 1;
    }
    cout << ans << endl;
    return 0;
}
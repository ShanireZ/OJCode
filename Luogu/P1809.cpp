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
    if (n == 1)
    {
        cout << a[1] << endl;
        return 0;
    }
    sort(a + 1, a + 1 + n);
    long long ans = 0;
    while (n > 3) // 每趟送最大的一对去对面
    {
        ans += min(a[1] + a[2] * 2 + a[n], a[1] * 2 + a[n] + a[n - 1]);
        n -= 2;
    }
    if (n == 3)
    {
        ans += a[2] + a[1] + a[3];
    }
    else if (n == 2)
    {
        ans += a[2];
    }
    cout << ans << endl;
    return 0;
}
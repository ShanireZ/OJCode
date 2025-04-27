#include <algorithm>
#include <iostream>
using namespace std;
long long n, tot, ans, a[100005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        tot += a[i];
    }
    tot /= n;
    for (int i = 1; i <= n; i++)
    {
        ans += (a[i] - tot) * (a[i] - tot);
    }
    cout << ans / n << endl;
    return 0;
}
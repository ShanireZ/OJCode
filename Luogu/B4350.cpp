#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int n, a[100005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n, greater<int>());
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += pow(a[i], pow(0.5, i - 1));
    }
    cout << ans << endl;
    return 0;
}
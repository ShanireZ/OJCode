#include <algorithm>
#include <iostream>
using namespace std;
long long a[200005], c[200005], ans = -1e15;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        c[i] = max(a[i], a[i] + c[i - 1]);
        ans = max(ans, c[i]);
    }
    cout << ans << endl;
    return 0;
}
#include <algorithm>
#include <iostream>
using namespace std;
int v[1005], n, k, ans;
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        v[a] += a;
    }
    for (int i = 1; i <= 1000; i++)
    {
        v[i] += v[i - 1];
    }
    for (int i = k + 1; i <= 1000; i++)
    {
        ans = max(ans, v[i] - v[i - k - 1]);
    }
    cout << ans << endl;
    return 0;
}
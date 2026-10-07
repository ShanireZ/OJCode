#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long n, ans = 0;
    cin >> n;
    for (int i = 1, now = 1; i <= n; i++, now += now)
    {
        ans += now;
    }
    cout << ans << endl;
    return 0;
}
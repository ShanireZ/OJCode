#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long cs = 0, ans = 0, pre = 0, n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        long long a;
        cin >> a;
        cs = (cs + a - pre <= 50 ? cs + a - pre : 50);
        pre = a, ans += cs / 8, cs %= 8;
    }
    cout << ans << endl;
    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    long long a, b, ans = 0;
    cin >> a >> b;
    while (a && b)
    {
        swap(a, b);
        ans += b * 4 * (a / b); //本次周长和 = 边长 * 4 * 个数
        a %= b;
    }
    cout << ans;
    return 0;
}
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long a, b, ca, cb, fa, ans = 0;
        cin >> a >> b >> ca >> cb >> fa;
        a += b / cb * ca;
        b %= cb, fa -= a;
        if (fa <= 0)
        {
            cout << 0 << endl;
            continue;
        }
        if (ca >= cb)
        {
            // 如果隨機晶片屬於B比較划算
            // 那就先浪費一些讓B晶片湊夠cb-1個(即將可進行兌換的狀態)
            // 然後再湊夠A晶片的數量,這樣能使浪費的數量儘可能多
            ans += cb - b - 1;
            ans += fa;
        }
        else
        {
            // 如果隨機晶片屬於A比較划算
            // 那就先讓A晶片所差的數量正好是ca的倍數+1，例如差15個而一次可以兌換4個A晶片，反正差15個和差13個都是需要換4次，那就先浪費2個
            // 剩下的部分由B兌換A補足
            ans += (fa - 1) % ca;
            fa -= (fa - 1) % ca;
            ans += (fa + ca - 1) / ca * cb - b;
        }
        cout << ans << endl;
    }
    return 0;
}
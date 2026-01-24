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
            // 如果随机芯片属于B比较划算
            // 那就先浪费一些让B芯片凑够cb-1个(即将可进行兑换的状态)
            // 然后再凑够A芯片的数量,这样能使浪费的数量尽可能多
            ans += cb - b - 1;
            ans += fa;
        }
        else
        {
            // 如果随机芯片属于A比较划算
            // 那就先让A芯片所差的数量正好是ca的倍数+1，例如差15个而一次可以兑换4个A芯片，反正差15个和差13个都是需要换4次，那就先浪费2个
            // 剩下的部分由B兑换A补足
            ans += (fa - 1) % ca;
            fa -= (fa - 1) % ca;
            ans += (fa + ca - 1) / ca * cb - b;
        }
        cout << ans << endl;
    }
    return 0;
}
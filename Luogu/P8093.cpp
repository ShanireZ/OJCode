#include <iostream>
#include <bitset>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, ans = 1e18;
        cin >> a >> b;
        // a->b的前綴->b 其中a->b的前綴，只需要用到除法和加法 b的前綴->b，只需要用到乘法和加法
        // 取出b的所有二進制前綴
        for (int i = 0; (b >> i) > 0; i++)
        {
            // prefix前綴 suffix後綴
            long long prefix = b >> i;
            bitset<64> suffix = b - (prefix << i);
            // 前綴->b 需要操作i次乘法+後綴中1的個數次加法
            long long cnt = i + suffix.count();
            // a->前綴
            long long now = a;
            while (now > prefix)
            {
                if (now & 1 == 1) // 奇數 先加一才能除
                {
                    now++, cnt++;
                }
                now >>= 1, cnt++; // 使用除法逼近
            }
            cnt += prefix - now; // 逼近後還有差距靠加法追平
            ans = min(ans, cnt);
        }
        cout << ans << endl;
    }
    return 0;
}
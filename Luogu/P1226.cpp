#include <iostream>
using namespace std;
int main()
{
    long long b, p, k;
    cin >> b >> p >> k;
    long long ans = 1 % k, base = b, pow = p; //ans儲存結果 base儲存每次運算的基 pow儲存次冪進行二進制運算
    while (pow != 0)                          //檢查 pow是否為0
    {
        //(a*b)mod c = (a mod c * b mod c) mod c
        if (pow & 1) //檢查pow的最右一位是否為1
        {
            ans *= base; //該位需要乘基
            ans %= k;    //a mod c 且 結果 mod c
        }
        base *= base; //計算下一輪的基
        base %= k;    //b mod c
        pow >>= 1;    //從右向左每次減少一位
    }
    cout << b << "^" << p << " mod " << k << "=" << ans;
    return 0;
}

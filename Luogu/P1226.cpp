#include <iostream>
using namespace std;
int main()
{
    long long b, p, k;
    cin >> b >> p >> k;
    long long ans = 1 % k, base = b, pow = p; //ans存储结果 base存储每次运算的基 pow存储次幂进行二进制运算
    while (pow != 0)                          //检查 pow是否为0
    {
        //(a*b)mod c = (a mod c * b mod c) mod c
        if (pow & 1) //检查pow的最右一位是否为1
        {
            ans *= base; //该位需要乘基
            ans %= k;    //a mod c 且 结果 mod c
        }
        base *= base; //计算下一轮的基
        base %= k;    //b mod c
        pow >>= 1;    //从右向左每次减少一位
    }
    cout << b << "^" << p << " mod " << k << "=" << ans;
    return 0;
}

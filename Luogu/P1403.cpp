#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int total = 1;               //1只有1个约数
    for (int i = 2; i <= n; i++) //从2开始计算有多少个约数
    {
        int tmp = i;
        int ans = 1; //存储当前数字i的约数个数
        while (tmp != 1)
        {
            bool trig = 1;                     //判断现解段所剩数字是否为质数
            for (int j = 2; j * j <= tmp; j++) //找质因数
            {
                int times = 0; //当前质因数j出现次数
                while (tmp % j == 0)
                {
                    tmp = tmp / j;
                    trig = 0;
                    times++;
                }
                if (trig == 0) //所剩数字不为质数
                {
                    ans *= (times + 1); //如果i = p1^a1 * p2 ^ a2 ... 且p1 p2...都为质数 那么i的约数个数为(a1+1) * (a2+!) * ...
                }
            }
            if (trig) //所剩数字为质数
            {
                ans *= 2;
                tmp = 1;
            }
        }
        total += ans;
    }
    cout << total;
    return 0;
}
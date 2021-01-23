#include <iostream>
using namespace std;
int prime[40005]; //i是否为质数
int main()
{
    int n;
    cin >> n;
    for (int i = 2; i <= n / 2; i++) //线性筛素数
    {
        if (prime[i] == 0)
        {
            int p = i;
            while (i * p <= n)
            {
                prime[i * p] = 1;
                p++;
            }
        }
    }
    int result = 0;
    //欧拉函数为 小于i且与i互质的正整数数量
    //公式详见 https://baike.baidu.com/item/%E6%AC%A7%E6%8B%89%E5%87%BD%E6%95%B0/1944850?fr=aladdin
    //本题要求求出斜率不相同的过原点线段数目，斜率k=y/x，也就是要求y和x互质
    //一旦不互质的y1 x1，必然有y1/x1 = y/x * a = a * k
    //利用欧拉函数逐个求出2~n-1每列的一半的值
    //最后记得加上第一列的情况
    for (int i = 2; i < n; i++)
    {
        int tmp = i;
        int all = i;
        //求i的质因数并套用欧拉函数
        while (prime[tmp] != 0 && tmp != 1)
        {
            for (int j = 2; j * j <= tmp; j++)
            {
                int trig = 1;
                while (tmp % j == 0)
                {
                    tmp /= j;
                    trig = 0;
                }
                if (trig == 0)
                {
                    all = all - all / j;
                }
            }
        }
        if (tmp != 1)
        {
            all = all - all / tmp;
        }
        result += all;
    }
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    cout << result * 2 + 3;
    return 0;
}
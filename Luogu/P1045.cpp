#include <iostream>
#include <cmath>
using namespace std;
int pre[505], base[505], aft[505]; //base儲存快速冪的基數 pre儲存當前乘積 att臨時中轉
int main()
{
    int p;
    cin >> p;
    cout << int(log10(2) * p + 1) << endl;
    //2^p末尾不為0所以 和 2^p-1位數相同 10^n共有n+1位 10^log(10)2 = 2 所以2^p = 10^[log(10)2 * p] 共有 log(10)2 * p + 1位
    pre[0] = 1; //快速冪初始化
    base[0] = 2;
    while (p) //快速冪
    {
        if (p & 1)
        {
            //高精乘
            for (int i = 0; i < 500; i++)
            {
                for (int j = 0; j < 500; j++)
                {
                    if (i + j >= 500)
                    {
                        break;
                    }
                    aft[i + j] += pre[i] * base[j];
                }
            }
            for (int i = 0; i < 500; i++)
            {
                while (aft[i] > 9)
                {
                    aft[i + 1]++;
                    aft[i] -= 10;
                }
                pre[i] = aft[i];
                aft[i] = 0;
            }
        }

        //基數高精乘
        for (int i = 0; i < 500; i++)
        {
            for (int j = 0; j < 500; j++)
            {
                if (i + j >= 500)
                {
                    break;
                }
                aft[i + j] += base[i] * base[j];
            }
        }
        for (int i = 0; i < 500; i++)
        {
            while (aft[i] > 9)
            {
                aft[i + 1]++;
                aft[i] -= 10;
            }
            base[i] = aft[i];
            aft[i] = 0;
        }
        p >>= 1;
    }

    pre[0] -= 1; //末尾-1
    int pos = 0;
    while (pre[pos] < 0 && pos < 500)
    {
        pre[pos + 1]--;
        pre[pos] += 10;
        pos++;
    }

    for (int i = 9; i >= 0; i--) //逐行輸出
    {
        for (int j = 49; j >= 0; j--)
        {
            cout << pre[i * 50 + j];
        }
        cout << endl;
    }
    return 0;
}
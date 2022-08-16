#include <iostream>
#include <string>
using namespace std;
int check[15];
int powers[15] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384};
string str[4] = {"2(0)", "2", "2(2)", "2(2+2(0))"};
string all;
int main()
{
    int n;
    cin >> n;
    while (n) //将n初次分解存入check中
    {
        for (int i = 14; i >= 0; i--)
        {
            if (n - powers[i] >= 0)
            {
                check[i] = 1;
                n -= powers[i];
                break;
            }
        }
    }
    for (int i = 14; i >= 0; i--) // 14最大的分解项目是2^3,所以1~14分解之用的到str[0~3]
    {
        if (check[i]) //如果之前n分解出来了相应次幂，需要输出
        {
            if (i < 4) // 0~3次幂可以直接调用已有
            {
                all.append(str[i]).append("+");
                continue;
            }
            int tmp = i;
            all.append("2("); //其他的次幂需要进一步分解
            while (tmp)
            {
                for (int j = 3; j >= 0; j--)
                {
                    if (tmp - powers[j] >= 0)
                    {

                        all.append(str[j]);
                        if (tmp > powers[j])
                        {
                            all.append("+");
                        }
                        tmp -= powers[j];
                        break;
                    }
                }
            }
            all.append(")+");
        }
    }
    all.erase(all.size() - 1, 1); //删除最后一个加号
    cout << all;
    return 0;
}
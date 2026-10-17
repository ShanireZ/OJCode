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
    while (n) //將n初次分解存入check中
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
    for (int i = 14; i >= 0; i--) // 14最大的分解專案是2^3,所以1~14分解之用的到str[0~3]
    {
        if (check[i]) //如果之前n分解出來了相應次冪，需要輸出
        {
            if (i < 4) // 0~3次冪可以直接呼叫已有
            {
                all.append(str[i]).append("+");
                continue;
            }
            int tmp = i;
            all.append("2("); //其他的次冪需要進一步分解
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
    all.erase(all.size() - 1, 1); //刪除最後一個加號
    cout << all;
    return 0;
}
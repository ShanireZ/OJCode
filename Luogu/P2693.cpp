#include <iostream>
#include <cstring>
using namespace std;
int n;

void reset(int &num) //环形取值
{
    if (num > n)
    {
        num -= n;
    }
    else if (num < 1)
    {
        num += n;
    }
}

int main()
{
    cin >> n;
    int pwd[6] = {0};      //存储两组密码
    int same_key[3] = {0}; //存储两组密码容错范围内每一位的重合数量
    for (int i = 0; i < 6; i++)
    {
        cin >> pwd[i];
    }
    if (n <= 5) //如果密码盘最大数n小于5，则全部情况都能开
    {
        cout << n * n * n;
        return 0;
    }

    for (int i = 0; i < 3; i++) //遍历每一位
    {
        for (int j = -2; j <= 2; j++) //遍历john容错范围内的每一种情况
        {
            int num_john = pwd[i] + j;
            reset(num_john);
            for (int k = -2; k <= 2; k++) //遍历初始密码容错范围内的每一种情况
            {
                int num_pre = pwd[i + 3] + k;
                reset(num_pre);
                if (num_john == num_pre) //如果两者相同，则两套密码在该位有一种重合
                {
                    same_key[i]++;
                }
            }
        }
    }
    cout << 250 - same_key[0] * same_key[1] * same_key[2]; //每一位重合数量相乘，则为总重合情况
    return 0;
}
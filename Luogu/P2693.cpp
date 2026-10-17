#include <iostream>
#include <cstring>
using namespace std;
int n;

void reset(int &num) //環形取值
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
    int pwd[6] = {0};      //儲存兩組密碼
    int same_key[3] = {0}; //儲存兩組密碼容錯範圍內每一位的重合數量
    for (int i = 0; i < 6; i++)
    {
        cin >> pwd[i];
    }
    if (n <= 5) //如果密碼盤最大數n小於5，則全部情況都能開
    {
        cout << n * n * n;
        return 0;
    }

    for (int i = 0; i < 3; i++) //遍歷每一位
    {
        for (int j = -2; j <= 2; j++) //遍歷john容錯範圍內的每一種情況
        {
            int num_john = pwd[i] + j;
            reset(num_john);
            for (int k = -2; k <= 2; k++) //遍歷初始密碼容錯範圍內的每一種情況
            {
                int num_pre = pwd[i + 3] + k;
                reset(num_pre);
                if (num_john == num_pre) //如果兩者相同，則兩套密碼在該位有一種重合
                {
                    same_key[i]++;
                }
            }
        }
    }
    cout << 250 - same_key[0] * same_key[1] * same_key[2]; //每一位重合數量相乘，則為總重合情況
    return 0;
}
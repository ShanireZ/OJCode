#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std; // 最小公倍数 = 最大公约数 * 两者独有的质因数(不重叠)
bool check[250005];  // i是否位质数
int main()
{
    int x, y, solo;
    cin >> x >> y;
    if (y % x != 0) // 若不能整除，说明给定的x y不配对
    {
        cout << 0;
        return 0;
    }
    solo = y / x;                  // 独有质因数的积
    for (int i = 2; i <= 500; i++) // y/x最大为50 0000,独有质因数最大为25 0000,筛法求范围内的质数
    {
        for (int j = 2; j <= 250000 / i; j++)
        {
            if (check[i * j] == 0)
            {
                check[i * j] = 1;
            }
        }
    }
    int total = 0; //计算组成积的质因数种类,将total种数分为有顺序的两组，共有2^total种分法
    for (int i = 2; i <= 250000; i++)
    {
        if (check[i] == 0)
        {
            if (solo % i == 0)
            {
                total++;
            }
        }
    }
    cout << pow(2, total);
    return 0;
}
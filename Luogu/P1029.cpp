#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std; // 最小公倍數 = 最大公約數 * 兩者獨有的質因數(不重疊)
bool check[250005];  // i是否位質數
int main()
{
    int x, y, solo;
    cin >> x >> y;
    if (y % x != 0) // 若不能整除，說明給定的x y不配對
    {
        cout << 0;
        return 0;
    }
    solo = y / x;                  // 獨有質因數的積
    for (int i = 2; i <= 500; i++) // y/x最大為50 0000,獨有質因數最大為25 0000,篩法求範圍內的質數
    {
        for (int j = 2; j <= 250000 / i; j++)
        {
            if (check[i * j] == 0)
            {
                check[i * j] = 1;
            }
        }
    }
    int total = 0; //計算組成積的質因數種類,將total種數分為有順序的兩組，共有2^total種分法
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
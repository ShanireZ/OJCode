#include <iostream>
#include <cstring>
using namespace std;
int total;
int a[23], b[23]; //a存储所有数字 b存储本次选取的数字
int m;

void choose(int n, int k)
{
    if (k > 0)
    {                                //从最后一个数开始选取 内层递归选取下个数字从本次前一个数开始选取 外层迭代每次往前一个数
        for (int i = n; i >= k; i--) //前方剩余数字不够时，循环停止
        {
            b[k - 1] = a[i - 1];  //将选取数字存入b中
            choose(i - 1, k - 1); //i和k为传值外层i k不变
        }
    }
    else
    {
        int s = 0, trig = 1;
        for (int i = 0; i < m; i++) //求和
        {
            s += b[i];
        }
        for (int i = 2; i < s; i++) //判断素数
        {
            if (s % i == 0)
            {
                trig = 0;
                break;
            }
        }
        if (trig) //素数统计
        {
            total++;
        }
    }
}

int main()
{
    int n, k; //总共n个数 选取k个 进行组合
    cin >> n >> k;
    m = k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    choose(n, k);
    cout << total;
    return 0;
}
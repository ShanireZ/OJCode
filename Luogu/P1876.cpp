#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    for (long long i = 1; i * i <= n; i++)
    {
        cout << i * i << " ";
    }
    // 每个灯的操作次数是奇数时最终会亮
    // 每个灯的操作次数和编号的因数个数有关,因为每个因数都会改变一次状态
    // 因数总是成对出现，只有完全平方数的因数个数是奇数
    return 0;
}
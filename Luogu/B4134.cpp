#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long sum = 0, n;
    cin >> n;
    // 操作次数为奇数的灯会亮，操作次数=编号的因数个数
    // 因为因数都是成对出现，所以只有完全平方数的因数个数是奇数
    for (int i = 1; i * i <= n; i++)
    {
        sum += i * i;
    }
    cout << sum << endl;
    return 0;
}
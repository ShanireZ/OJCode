#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long sum = 0, n;
    cin >> n;
    // 操作次數為奇數的燈會亮，操作次數=編號的因數個數
    // 因為因數都是成對出現，所以只有完全平方數的因數個數是奇數
    for (int i = 1; i * i <= n; i++)
    {
        sum += i * i;
    }
    cout << sum << endl;
    return 0;
}
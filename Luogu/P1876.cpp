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
    // 每個燈的操作次數是奇數時最終會亮
    // 每個燈的操作次數和編號的因數個數有關,因為每個因數都會改變一次狀態
    // 因數總是成對出現，只有完全平方數的因數個數是奇數
    return 0;
}
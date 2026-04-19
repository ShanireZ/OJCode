#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long a = 2026202620262026ll;                                      // 51位 26个1 25个0
    long long x1 = 0b11111111111111111111111110000000000000000000000000;   // 50位最大
    long long x2 = 0b1000000000000000000000000001111111111111111111111111; // 52位最小
    if (a - x1 <= x2 - a)
    {
        cout << x1 << endl;
    }
    else
    {
        cout << x2 << endl;
    }
    return 0;
}
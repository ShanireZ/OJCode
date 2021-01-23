#include <iostream>
#include <cmath>
using namespace std;
//k = 3时，序列为
//1,3,4,9,10,12,13,…
//也就是3^0 3^1 3^0+3^1 3^2 3^0+3^2 3^1+3^2 3^0+3^1+3^2
//转换三进制后为1 10 11 100 101 110 111
//把这些数当作二进制数转换为十进制后为1 2 3 4 5 6 7
//那么第n项为n
//先把n转为二进制数，然后把该数当作三进制数转换为十进制
int main()
{
    int k, n;
    cin >> k >> n;
    long long binaryN = 0;
    int pos = 0;
    while (n != 0)
    {
        binaryN = n % 2 * pow(10, pos) + binaryN;
        pos++;
        n /= 2;
    }
    long long s = 0;
    pos = 0;
    while (binaryN != 0)
    {
        s += binaryN % 10 * pow(k, pos);
        binaryN /= 10;
        pos++;
    }
    cout << s;
    return 0;
}
#include <iostream>
#include <cmath>
using namespace std;
//k = 3時，序列為
//1,3,4,9,10,12,13,…
//也就是3^0 3^1 3^0+3^1 3^2 3^0+3^2 3^1+3^2 3^0+3^1+3^2
//轉換三進制後為1 10 11 100 101 110 111
//把這些數當作二進制數轉換為十進制後為1 2 3 4 5 6 7
//那麼第n項為n
//先把n轉為二進制數，然後把該數當作三進制數轉換為十進制
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
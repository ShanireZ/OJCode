#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int x, y, n;
    cin >> x >> y >> n;
    cout << n / x + n / y - n / (x * y / __gcd(x, y)) << endl;
    return 0;
}
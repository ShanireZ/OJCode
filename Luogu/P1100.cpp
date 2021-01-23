#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    long long x;
    cin >> x;
    long long m = pow(2, 16);
    long long ans = x % m * m + x / m; //!低位 * m + 高位
    cout << ans;
    return 0;
}
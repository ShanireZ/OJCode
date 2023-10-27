#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    long long n, m, a;
    cin >> n >> m >> a;
    n = ceil(1.0 * n / a), m = ceil(1.0 * m / a);
    cout << n * m << endl;
    return 0;
}
// TAG: 数学 整除 取整
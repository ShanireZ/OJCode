#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    int n, k, p, q;
    cin >> n >> k >> p >> q;
    int x = ceil(1.0 * k * q / p - n);
    cout << max(0, x) << endl;
    return 0;
}
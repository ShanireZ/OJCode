#include <iostream>
using namespace std;
int main()
{
    long long a, b, k, r, c;
    cin >> a >> b >> k >> r >> c;
    cout << (r - c) * k * (b - a) << "\n";
    return 0;
}
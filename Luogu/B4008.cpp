#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int a, b, c = 10000;
    cin >> a >> b;
    a /= 10, b *= 10;
    c -= a + b;
    cout << a << " " << b << " " << c << endl;
    return 0;
}
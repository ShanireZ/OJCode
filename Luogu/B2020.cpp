#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int a, b, c, d, e, tot = 0;
    cin >> a >> b >> c >> d >> e;
    tot += a + b + c + d + e;
    a = a / 3, e = e + a, b = b + a;
    b = b / 3, a = a + b, c = c + b;
    c = c / 3, b = b + c, d = d + c;
    d = d / 3, c = c + d, e = e + d;
    e = e / 3, d = d + e, a = a + e;
    tot -= a + b + c + d + e;
    cout << a << " " << b << " " << c << " " << d << " " << e << endl;
    cout << tot << endl;
}
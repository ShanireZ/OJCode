#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    char a;
    int b;
    float c;
    double d;
    cin >> a >> b >> c >> d;
    cout << a << " " << b << " ";
    cout << fixed << setprecision(6) << c << " " << d << endl;
    return 0;
}
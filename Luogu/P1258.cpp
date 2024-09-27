#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    double s, a, b;
    cin >> s >> a >> b;
    double x = (a + b) * (a + b) / (b - a) + a;
    double t2 = s / x;
    double t1 = (a + b) / (b - a) * t2;
    cout << fixed << setprecision(6) << t1 + t1 + t2 << endl;
    return 0;
}
// TAG: 数学
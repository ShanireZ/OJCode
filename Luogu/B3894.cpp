#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    double len = a * b + c * d;
    cout << fixed << setprecision(1) << len << endl;
    cout << fixed << setprecision(1) << len / (b + d) << endl;
    return 0;
}
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    double r;
    cin >> r;
    cout << fixed << setprecision(4) << r * 2 << " ";
    cout << 2 * 3.14159 * r << " ";
    cout << 3.14159 * r * r << endl;
    return 0;
}
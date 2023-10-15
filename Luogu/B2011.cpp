#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    cout << fixed << setprecision(9) << 1.0 * a / b;
    return 0;
}
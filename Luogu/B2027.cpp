#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int r;
    cin >> r;
    cout << fixed << setprecision(5) << 4 / 3.0 * 3.14 * r * r * r << endl;
    return 0;
}
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    cout << fixed << setprecision(3) << 100.0 * b / a << "%" << endl;
    return 0;
}
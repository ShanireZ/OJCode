#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    int x = 1.0 / a * b;
    double ans = 1.0 * x / b;
    cout << ans << endl;
    return 0;
}
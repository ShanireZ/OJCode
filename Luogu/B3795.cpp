#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int a, b, c, wa, wb, wc;
    cin >> a >> b >> c >> wa >> wb >> wc;
    int c1 = (a < 60) + (b < 60) + (c < 60);
    if (c1 <= 1)
    {
        cout << "PASS\n";
    }
    else
    {
        cout << "FAIL\n";
    }
    double c2 = 1.0 * (a * wa + b * wb + c * wc) / (wa + wb + wc);
    if (c2 >= 60)
    {
        cout << "PASS\n";
    }
    else
    {
        cout << "FAIL\n";
    }
    return 0;
}
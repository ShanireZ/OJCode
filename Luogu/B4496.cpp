#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int a, b = 0, c = 1;
    cin >> a;
    while (a)
    {
        if (a % 10 == 4)
        {
            b += 8 * c;
        }
        else
        {
            b += a % 10 * c;
        }
        c *= 10, a /= 10;
    }
    cout << b << endl;
    return 0;
}
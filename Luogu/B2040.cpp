#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int a;
    cin >> a;
    if (a > 9 && a < 100)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    return 0;
}
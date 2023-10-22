#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int x;
    cin >> x;
    if (x % 3 == 0)
    {
        cout << "3 ";
    }
    if (x % 5 == 0)
    {
        cout << "5 ";
    }
    if (x % 7 == 0)
    {
        cout << "7 ";
    }
    if (x % 3 != 0 && x % 5 != 0 && x % 7 != 0)
    {
        cout << "n";
    }
    cout << endl;
    return 0;
}
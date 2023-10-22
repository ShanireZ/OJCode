#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int x;
    cin >> x;
    if (x % 3 == 0 && x % 5 == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
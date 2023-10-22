#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int x;
    cin >> x;
    if (x % 2 == 0)
    {
        cout << "even" << endl;
    }
    else
    {
        cout << "odd" << endl;
    }
    return 0;
}
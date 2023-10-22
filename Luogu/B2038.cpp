#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    char c;
    cin >> c;
    if ((int)c % 2 == 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
    return 0;
}
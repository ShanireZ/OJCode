#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int c, t;
    cin >> c >> t;
    int p = t - c;
    int e = c - p;
    if (p < 1 || e < 0)
    {
        cout << "Error" << endl;
    }
    else
    {
        cout << p << " " << e << endl;
    }
    return 0;
}
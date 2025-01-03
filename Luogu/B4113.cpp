#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int p, q, a, b;
    cin >> p >> q >> a >> b;
    if (q > p)
    {
        cout << a * p + b * (q - p) << endl;
    }
    else
    {
        cout << a * q << endl;
    }
    return 0;
}
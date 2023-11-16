#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int x, y, z, q, p;
    cin >> x >> y >> z >> q;
    p = x * 2 + y * 5 + z * 3;
    if (p <= q)
    {
        cout << "Yes" << endl;
        cout << q - p << endl;
    }
    else
    {
        cout << "No" << endl;
        cout << p - q << endl;
    }
    return 0;
}
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    char x, z;
    long long y, w;
    cin >> x >> y >> z >> w;
    if (x >= 'a' && x <= 'z' && z >= 'a' && z <= 'z' && x == z)
    {
        cout << "valid\n";
        cout << abs(y - w) + 1 << "\n";
    }
    else
    {
        cout << "Invalid\n-1\n";
    }
    return 0;
}
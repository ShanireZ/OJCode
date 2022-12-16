#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int x, y, z;
    cin >> x >> y >> z;
    cout << (x > y + z ? y + z : x) << '\n';
    cout << (y > x + z ? x + z : y) << '\n';
    cout << (z > x + y ? x + y : z) << '\n';
    return 0;
}
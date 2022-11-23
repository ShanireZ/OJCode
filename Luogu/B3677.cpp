#include <iostream>
using namespace std;
int main()
{
    long long y, t;
    cin >> y >> t;
    if (y < 0 && t % 2 == 1)
    {
        cout << "YES" << '\n';
    }
    else
    {
        cout << "NO" << '\n';
    }
    if (y % 2 == 1 || y % 2 == -1 || t == 0)
    {
        cout << "YES" << '\n';
    }
    else
    {
        cout << "NO" << '\n';
    }
    return 0;
}
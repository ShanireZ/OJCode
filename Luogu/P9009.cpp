#include <iostream>
using namespace std;
int main()
{
    int id;
    cin >> id;
    if (id == 1)
    {
        cout << 1 << "\n"
             << -1 << "\n";
    }
    else if (id == 2)
    {
        cout << (long long)2147580959 << "\n";
    }
    else
    {
        cout << 1 << "\n"
             << 1 << "\n";
    }
    return 0;
}
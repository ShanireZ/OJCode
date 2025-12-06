#include <iostream>
using namespace std;
int main()
{
    int x;
    cin >> x;
    while (x)
    {
        cout << x % 10 << " ";
        x /= 10;
    }
    return 0;
}
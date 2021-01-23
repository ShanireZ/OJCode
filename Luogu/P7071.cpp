#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n % 2 == 1)
    {
        cout << -1;
        return 0;
    }
    while (n > 1)
    {
        int x = log2(n);
        int base = pow(2, x);
        if (n >= base)
        {
            n -= base;
            cout << base << " ";
        }
    }
    return 0;
}
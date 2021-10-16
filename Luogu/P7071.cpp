#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n % 2 == 1)
    {
        cout << -1 << endl;
    }
    else
    {
        while (n)
        {
            int x = log2(n);
            x = pow(2, x);
            n -= x;
            cout << x << " ";
        }
    }
    return 0;
}
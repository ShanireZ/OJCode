#include <iostream>
using namespace std;
int main()
{
    long long x, k;
    cin >> x >> k;
    while (k)
    {
        k--, x++;
        if (x % 3 == 0)
        {
            x /= 3;
            if (x == 1)
            {
                break;
            }
        }
    }
    cout << x + k % 2 << endl;
    return 0;
}
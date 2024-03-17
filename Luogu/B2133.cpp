#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    for (long long i = 3;; i++)
    {
        long long x3 = i * (i + 1) / 2 - n;
        if (x3 > 0 && x3 % 3 == 0)
        {
            cout << x3 / 3 << " " << i << endl;
            break;
        }
    }
    return 0;
}
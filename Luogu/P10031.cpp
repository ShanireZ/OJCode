#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long n;
        cin >> n;
        if (n % 2 == 1)
        {
            cout << n << endl;
        }
        else
        {
            cout << (n ^ (n / 2)) << endl;
        }
    }
    return 0;
}
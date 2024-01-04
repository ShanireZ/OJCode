#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long p, a, b, c;
        cin >> p >> a >> b >> c;
        if (c != 0 && (b == 0 || p == 1))
        {
            cout << "No" << endl;
        }
        else if (c % 2 == 1 && p % 2 == 0 && b % 2 == 0)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
    return 0;
}
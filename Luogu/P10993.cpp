#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int a;
    cin >> a;
    a *= 37;
    int x = a % 10;
    while (a)
    {
        if (a % 10 != x)
        {
            cout << "No" << endl;
            return 0;
        }
        a /= 10;
    }
    cout << "Yes" << endl;
    return 0;
}
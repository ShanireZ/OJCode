#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    for (int x = 2; x <= 1000000; x++)
    {
        if (a % x == b % x && b % x == c % x)
        {
            cout << x << endl;
            return 0;
        }
    }
    return 0;
}
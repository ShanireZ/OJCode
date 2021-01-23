#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << 0;
        return 0;
    }
    if (n < 0)
    {
        cout << '-';
        n = -n;
    }
    int m = 0;
    while (n != 0)
    {
        m = m * 10 + n % 10;
        n = n / 10;
    }
    cout << m;
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    unsigned long long x;
    char m1, m2;
    cin >> x >> m1 >> m2;
    if (m1 > m2)
    {
        swap(m1, m2);
    }
    if (m1 == 'B' || m2 == 'B')
    {
        if (m2 != 'C')
        {
            cout << x / 10 * 8;
        }
        else
        {
            cout << x / 10 * 6;
        }
    }
    else if (m1 == 'C' || m2 == 'C')
    {
        cout << x / 10 * 7;
    }
    else
    {
        cout << x;
    }
    return 0;
}
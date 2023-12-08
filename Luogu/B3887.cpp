#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int c3 = 0, c8 = 0, c10 = 0;
    for (int i = 1; i <= 8; i++)
    {
        int f;
        cin >> f;
        if (f >= 41)
        {
            c3++;
        }
        if (f >= 63)
        {
            c8++;
        }
        if (f >= 118)
        {
            c10++;
        }
    }
    if (c10)
    {
        cout << 10 << endl;
    }
    else if (c8 >= 4)
    {
        cout << 8 << endl;
    }
    else if (c3 >= 4)
    {
        cout << 3 << endl;
    }
    else
    {
        cout << 1 << endl;
    }
    return 0;
}
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    for (int i = 0; i < 3; i++)
    {
        if (a[i] == 1)
        {
            cout << 'B';
        }
        else if (a[i] == 2)
        {
            cout << 'Y';
        }
        else
        {
            cout << 'R';
        }
    }
    return 0;
}
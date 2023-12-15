#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    int a;
    cin >> a;
    for (int i = 0; i <= 100; i++)
    {
        int x = sqrt(i) * 10;
        if (x >= a)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
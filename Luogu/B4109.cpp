#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int x, p = 0;
    cin >> x;
    for (int i = 1; i <= x; i++)
    {
        p += (i % 2 == 1 ? 3 : -2);
    }
    cout << p << endl;
    return 0;
}
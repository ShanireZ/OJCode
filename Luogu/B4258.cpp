#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        if (x % 10 < 5)
        {
            cout << x - x % 10 << endl;
        }
        else
        {
            cout << (x + 5) - (x + 5) % 10 << endl;
        }
    }
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int x, y;
    cin >> x >> y;
    if (x > y)
    {
        cout << "no\n";
    }
    else if (x < y)
    {
        cout << "yes\n";
    }
    else
    {
        cout << "equal probability\n";
    }
    return 0;
}
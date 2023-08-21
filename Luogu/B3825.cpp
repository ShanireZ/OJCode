#include <iostream>
using namespace std;
int main()
{
    int x, h;
    cin >> x >> h;
    if (x < 10)
    {
        cout << "Drizzle\n";
    }
    else if (x < 25)
    {
        cout << "Moderate Rain\n";
    }
    else if (x < 50)
    {
        cout << "Heavy Rain\n";
    }
    else
    {
        cout << "Torrential Rain\n";
    }
    if (h == 1 && x >= 20)
    {
        cout << "YES\n";
    }
    else if (h == 1)
    {
        cout << "NO\n";
    }
    return 0;
}
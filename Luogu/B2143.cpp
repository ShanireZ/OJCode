#include <algorithm>
#include <iostream>
using namespace std;
void zh(int x, int m)
{
    if (x / m != 0)
    {
        zh(x / m, m);
    }
    if (x % m > 9)
    {
        char c = 'A' + x % m - 10;
        cout << c;
    }
    else
    {
        cout << x % m;
    }
}
int main()
{
    int x, m;
    cin >> x >> m;
    zh(x, m);
    return 0;
}
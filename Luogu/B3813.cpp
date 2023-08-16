#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a + b + c + d < 51)
    {
        cout << "Rabbit wins\n";
    }
    else
    {
        cout << "Rabbit lose\n";
    }
    return 0;
}
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long a, b, c;
    cin >> a >> b >> c;
    if (a + b + c <= 100 && b % 5 == 0 && c % 7 == 0 && a - b > b - c)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}
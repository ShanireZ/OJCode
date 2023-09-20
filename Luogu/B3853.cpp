#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long a, b, c;
    cin >> a >> b >> c;
    if (a + b == c)
    {
        cout << "plus" << endl;
    }
    else if (a - b == c)
    {
        cout << "minus" << endl;
    }
    else
    {
        cout << "illegal" << endl;
    }
    return 0;
}
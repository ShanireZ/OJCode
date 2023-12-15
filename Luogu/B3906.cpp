#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a * d < -2147483648 || c * b < -2147483648 || a * c > 2147483647 || b * d > 2147483647)
    {
        cout << "long long int" << endl;
    }
    else
    {
        cout << "int" << endl;
    }
    return 0;
}
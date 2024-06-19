#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long a, b;
    cin >> a >> b;
    long long g = __gcd(a, b);
    cout << g << " " << a / g * b << endl;
    return 0;
}
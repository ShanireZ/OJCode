#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    long long a, b;
    cin >> a >> b;
    a = ceil((a - b) / 100.0);
    cout << a << "\n";
    return 0;
}
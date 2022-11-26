#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    long long a, b;
    cin >> a >> b;
    cout << b / abs(b) * abs(a) << '\n';
    return 0;
}
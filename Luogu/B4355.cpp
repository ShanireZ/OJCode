#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    cout << a * b / __gcd(a, b) << endl;
    return 0;
}
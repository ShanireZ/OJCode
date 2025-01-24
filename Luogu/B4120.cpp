#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    a %= 10;
    cout << (a <= b ? b - a : 10 + b - a) << endl;
    return 0;
}
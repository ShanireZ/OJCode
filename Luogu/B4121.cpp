#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    int x = a / 2, y = b / 2;
    cout << (a % 2 == b % 2 ? abs(x - y) - 1 : x + y) << endl;
    return 0;
}
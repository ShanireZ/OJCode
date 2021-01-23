#include <iostream>
using namespace std;
int main()
{
    double a;
    cin >> a;
    int b = a * 10;
    cout << b % 10 << ".";
    b = b / 10;
    cout << b % 10;
    b = b / 10;
    cout << b % 10;
    b = b / 10;
    cout << b % 10;
    return 0;
}
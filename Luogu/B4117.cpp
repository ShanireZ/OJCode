#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << (a + b + c <= 21 ? 1 : 0) << endl;
    return 0;
}
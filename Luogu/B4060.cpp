#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long a, b, k;
    cin >> a >> b >> k;
    cout << (a & b) << endl;
    cout << (a | b) << endl;
    cout << (a ^ b) << endl;
    cout << (~a) << endl;
    cout << (a << k) << endl;
    cout << (a >> k) << endl;
    return 0;
}
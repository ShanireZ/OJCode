#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int a, s;
    cin >> a >> s;
    int b = s / a;
    cout << a + a + b + b << endl;
    return 0;
}
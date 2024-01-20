#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long a, b, n;
    cin >> a >> b >> n;
    cout << min(n, a / b) * b << endl;
    return 0;
}
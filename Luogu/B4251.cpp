#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    unsigned long long a, b;
    cin >> a >> b;
    cout << ((a % 2 == 0 || b % 2 == 0) ? "Yes" : "No") << endl;
    return 0;
}
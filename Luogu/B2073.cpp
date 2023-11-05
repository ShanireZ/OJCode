#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int a, b, n;
    cin >> a >> b >> n;
    for (int i = 1; i <= n; i++)
    {
        a = a % b * 10;
    }
    cout << a / b << endl;
    return 0;
}
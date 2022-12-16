#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int a = n / 100 + n / 10 % 10 + n % 10;
    cout << a << '\n'
         << a * a << '\n'
         << a * a * a << '\n';
    return 0;
}
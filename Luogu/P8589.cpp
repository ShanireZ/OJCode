#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "0" << endl;
        return 0;
    }
    n -= 5;
    if (n < 0 || n % 4 != 0)
    {
        cout << -1 << endl;
        return 0;
    }
    n /= 4;
    cout << "00110";
    for (int i = 1; i <= n; i++)
    {
        cout << "0110";
    }
    cout << endl;
    return 0;
}
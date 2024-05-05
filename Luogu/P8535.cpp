#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int x = n / 5, y = n % 5;
    cout << (y >= 3 ? 2 : 1);
    for (int i = 1; i < x; i++)
    {
        cout << 1;
    }
    return 0;
}
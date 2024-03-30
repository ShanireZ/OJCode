#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << '|';
        for (int j = 2; j < n; j++)
        {
            if (i == 1 || i == n || i == n / 2 + 1)
            {
                cout << '-';
            }
            else
            {
                cout << 'x';
            }
        }
        cout << '|' << '\n';
    }
    return 0;
}
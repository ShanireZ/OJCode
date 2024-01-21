#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 1, p1 = 1, p2 = n; i <= n; i++, p1++, p2--)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j == p1 || j == p2)
            {
                cout << '+';
            }
            else
            {
                cout << '-';
            }
        }
        cout << endl;
    }
    return 0;
}
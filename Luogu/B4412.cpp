#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int l = n / 2 + 1, r = n / 2 + 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << ((j == l || j == r) ? '#' : '.');
        }
        cout << endl;
        (i <= n / 2) ? (l--, r++) : (l++, r--);
    }
    return 0;
}
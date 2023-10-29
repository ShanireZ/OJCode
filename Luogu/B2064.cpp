#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a = 1, b = 1, c, n;
        cin >> n;
        for (int i = 3; i <= n; i++)
        {
            c = a + b;
            a = b, b = c;
        }
        cout << b << endl;
    }
    return 0;
}
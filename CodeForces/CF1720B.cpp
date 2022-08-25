#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a = 0, b = 0, c = 1e9 + 5, d = 1e9 + 5;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            if (x > a)
            {
                b = a;
                a = x;
            }
            else if (x > b)
            {
                b = x;
            }
            if (x < c)
            {
                d = c;
                c = x;
            }
            else if (x < d)
            {
                d = x;
            }
        }
        cout << a + b - c - d << endl;
    }
    return 0;
}
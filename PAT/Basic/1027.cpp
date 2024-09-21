#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, nd = 1, h = 1;
    char c;
    cin >> n >> c;
    while (nd + ((h + 1) * 2 - 1) * 2 <= n)
    {
        nd += (++h * 2 - 1) * 2;
    }
    for (int i = h; i > 1; i--)
    {
        int c1 = i * 2 - 1, c0 = h * 2 - 1 - c1;
        for (int j = 1; j <= c0 / 2; j++)
        {
            cout << ' ';
        }
        for (int j = 1; j <= c1; j++)
        {
            cout << c;
        }
        cout << endl;
    }
    for (int i = 1; i <= h; i++)
    {
        int c1 = i * 2 - 1, c0 = h * 2 - 1 - c1;
        for (int j = 1; j <= c0 / 2; j++)
        {
            cout << ' ';
        }
        for (int j = 1; j <= c1; j++)
        {
            cout << c;
        }
        cout << endl;
    }
    cout << n - nd << endl;
    return 0;
}
#include <algorithm>
#include <iostream>
using namespace std;
int n, i, j;
int main()
{
    cin >> n >> i >> j;
    for (int x = 1; x <= n; x++)
    {
        cout << "(" << i << "," << x << ") ";
    }
    cout << endl;
    for (int x = 1; x <= n; x++)
    {
        cout << "(" << x << "," << j << ") ";
    }
    cout << endl;
    int x = min(i - 1, j - 1);
    for (int add = 0; i - x + add <= n && j - x + add <= n; add++)
    {
        cout << "(" << i - x + add << "," << j - x + add << ") ";
    }
    cout << endl;
    x = min(n - i, j - 1);
    for (int add = 0; i + x - add >= 1 && j - x + add <= n; add++)
    {
        cout << "(" << i + x - add << "," << j - x + add << ") ";
    }
    return 0;
}
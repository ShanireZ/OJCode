#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    int n;
    char c;
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        cout << c;
    }
    cout << "\n";
    int x = round(n / 2.0);
    for (int i = 2; i < x; i++)
    {
        cout << c;
        for (int j = 2; j < n; j++)
        {
            cout << " ";
        }
        cout << c << "\n";
    }
    for (int i = 1; i <= n; i++)
    {
        cout << c;
    }
    return 0;
}
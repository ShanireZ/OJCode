#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << "|";
        char c = (i == n / 2 + 1 ? '-' : 'a');
        for (int j = 2; j < n; j++)
        {
            cout << c;
        }
        cout << "|\n";
    }
    return 0;
}
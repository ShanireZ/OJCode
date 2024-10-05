#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << ((j == n || j == 1 || i == j) ? '+' : '-');
        }
        cout << endl;
    }
    return 0;
}
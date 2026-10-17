#include <algorithm>
#include <iostream>
using namespace std;
int n, m, a[105][105];
int main()
{
    cin >> n >> m;
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= m - 1; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int j = 0; j <= m - 1; j++) //! 列舉列號
    {
        for (int i = n - 1; i >= 0; i--) //! 列舉行號
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
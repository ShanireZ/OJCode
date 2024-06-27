#include <algorithm>
#include <iostream>
using namespace std;
char mp[55][55];
int main()
{
    int n;
    cin >> n;
    for (int i = 2; i < n; i++)
    {
        for (int j = 2; j < n; j++)
        {
            mp[i][j] = 'x';
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j += n / 2)
        {
            mp[i][j] = '|';
        }
    }
    for (int i = 1; i <= n; i += n / 2)
    {
        for (int j = 2; j < n; j++)
        {
            mp[i][j] = '-';
        }
    }
    mp[n / 2 + 1][n / 2 + 1] = 'x';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << mp[i][j];
        }
        cout << endl;
    }
    return 0;
}
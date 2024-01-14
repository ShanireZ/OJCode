#include <algorithm>
#include <iostream>
using namespace std;
int a[8][8], n, m;
int main()
{
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            cin >> a[i][j];
        }
    }
    cin >> m >> n;
    for (int j = 1; j <= 5; j++)
    {
        swap(a[m][j], a[n][j]);
    }
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
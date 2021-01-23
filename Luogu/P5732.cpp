#include <iostream>
using namespace std;
int san[25][25];
int main()
{
    int n;
    cin >> n;
    san[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            san[i][j] = san[i - 1][j] + san[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << san[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
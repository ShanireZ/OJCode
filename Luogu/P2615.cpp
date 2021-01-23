#include <iostream>
using namespace std;
int cube[50][50];
int main()
{
    int n;
    cin >> n;
    int x = 1, y = n / 2 + 1;
    cube[x][y] = 1;
    for (int i = 2; i <= n * n; i++)
    {
        if (x == 1 && y != n)
        {
            x = n, y = y + 1;
        }
        else if (x != 1 && y == n)
        {
            x = x - 1, y = 1;
        }
        else if (x == 1 && y == n)
        {
            x = x + 1;
        }
        else if (x != 1 && y != n)
        {
            if (cube[x - 1][y + 1] == 0)
            {
                x = x - 1, y = y + 1;
            }
            else
            {
                x = x + 1;
            }
        }
        cube[x][y] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << cube[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
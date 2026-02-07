#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    for (int i = 1; i <= 4; i++)
    {
        int a[5] = {0, 0, 0, 0, 0}, x;
        for (int j = 1; j <= 4; j++)
        {
            cin >> x;
            a[x] = 1;
        }
        for (int j = 1; j <= 4; j++)
        {
            if (a[j] == 0)
            {
                cout << j << endl;
                return 0;
            }
        }
    }
    return 0;
}
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= a; j++)
        {
            if (i >= a / 2 - b / 2 + 1 && i <= a / 2 - b / 2 + b &&
                j >= a / 2 - b / 2 + 1 && j <= a / 2 - b / 2 + b)
            {
                cout << ' ';
            }
            else
            {
                cout << '*';
            }
        }
        cout << endl;
    }
    return 0;
}
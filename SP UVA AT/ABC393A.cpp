#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int c1 = 0, c2 = 0, c3 = 0;
    for (int i = 1; i <= 3; i++)
    {
        char c;
        cin >> c;
        if (c == 'a')
        {
            c1++;
        }
        else if (c == 'b')
        {
            c2++;
        }
        else
        {
            c3++;
        }
    }
    if (c1 == c2 && c2 == c3 && c1 == 1)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
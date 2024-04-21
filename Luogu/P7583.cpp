#include <algorithm>
#include <iostream>
using namespace std;
char c[10] = {'C', 'A', 'M', 'B', 'R', 'I', 'D', 'G', 'E'};
int main()
{
    char n;
    while (cin >> n)
    {
        int ok = 1;
        for (int i = 0; i < 9; i++)
        {
            if (n == c[i])
            {
                ok = 0;
                break;
            }
        }
        if (ok)
        {
            cout << n;
        }
    }
    return 0;
}
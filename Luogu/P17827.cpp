#include <algorithm>
#include <iostream>
using namespace std;
string a1, a2, b1, b2;
int main()
{
    cin >> a1 >> a2 >> b1 >> b2;
    if (a2[2] == 'D')
    {
        a2[2] = 'E';
    }
    if (b2[2] == 'D')
    {
        b2[2] = 'E';
    }
    if (a1 != b1)
    {
        cout << "0000" << endl;
    }
    else if (a2[0] != b2[0] || a2[1] != b2[1])
    {
        cout << "1000" << endl;
    }
    else if ((a2[2] <= 'C') ^ (b2[2] <= 'C'))
    {
        cout << "1100" << endl;
    }
    else if (abs(a2[2] - b2[2]) != 1)
    {
        cout << "1110" << endl;
    }
    else
    {
        cout << "1111" << endl;
    }
    return 0;
}
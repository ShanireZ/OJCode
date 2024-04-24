#include <algorithm>
#include <iostream>
using namespace std;
int ca, cb, cc, cd;
int main()
{
    for (int i = 1; i <= 4; i++)
    {
        char ch;
        cin >> ch;
        if (ch == 'A')
        {
            ca++;
        }
        else if (ch == 'B')
        {
            cb++;
        }
        else if (ch == 'C')
        {
            cc++;
        }
        else if (ch == 'D')
        {
            cd++;
        }
    }
    if (cc == 0 && cd == 0 && ca)
    {
        cout << "I'm so happy." << endl;
    }
    else if (cd == 0)
    {
        cout << "This is ok." << endl;
    }
    else
    {
        cout << "Never give up." << endl;
    }
    return 0;
}
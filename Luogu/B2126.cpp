#include <iostream>
#include <string>
using namespace std;
int main()
{
    int k, cs = 0;
    cin >> k;
    char c, pre = '0';
    while (cin >> c)
    {
        if (c == pre)
        {
            cs++;
            if (cs >= k)
            {
                cout << pre << endl;
                return 0;
            }
        }
        else
        {
            cs = 1, pre = c;
        }
    }
    cout << "No" << endl;
    return 0;
}
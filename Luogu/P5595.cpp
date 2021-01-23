#include <iostream>
#include <string>
using namespace std;
string ans, ansx, ansy;
int main()
{
    cin >> ans;
    int trig = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] == 'Z')
        {
            ansx += '0';
            ansy += '0';
            trig = 1;
        }
        else if (ans[i] == 'X')
        {
            if (trig)
            {
                cout << -1;
                return 0;
            }
            ansx += '1';
            ansy += '0';
        }
        else
        {
            if (trig)
            {
                cout << -1;
                return 0;
            }
            ansx += '0';
            ansy += '1';
        }
    }
    cout << ansx << endl
         << ansy;
    return 0;
}
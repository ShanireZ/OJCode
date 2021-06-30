#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        string s;
        cin >> s;
        int k;
        cin >> k;
        if(s[0] == 'x' && s[2] == 'z')
        {
            k /= 2;
        }
        cout << k * 3 << " " << k * 2 << " " << k << endl;
    }
    return 0;
}
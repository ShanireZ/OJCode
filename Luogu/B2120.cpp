#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    int c = 1;
    while (cin >> s)
    {
        if (c != 1)
        {
            cout << ",";
        }
        cout << s.size();
        c++;
    }
    return 0;
}
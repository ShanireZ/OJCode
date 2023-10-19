#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    if (s1 > s2)
    {
        swap(s1, s2);
    }
    if (s2.find(s1) != string::npos)
    {
        cout << s1 << " is substring of " << s2 << endl;
    }
    else
    {
        cout << "No substring" << endl;
    }
    return 0;
}
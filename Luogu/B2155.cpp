#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if ((isdigit(s[i]) && i > 0) || isalpha(s[i]) || s[i] == '_')
        {
            continue;
        }
        cout << "no" << endl;
        return 0;
    }
    cout << "yes" << endl;
    return 0;
}
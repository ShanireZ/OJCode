#include <algorithm>
#include <iostream>
using namespace std;
string s;
int main()
{
    cin >> s;
    for (int i = 0; i < (int)s.size() - 1;)
    {
        if (s[i] == 'W' && s[i + 1] == 'A')
        {
            s[i] = 'A', s[i + 1] = 'C';
            i--;
        }
        else
        {
            i++;
        }
    }
    cout << s << endl;
    return 0;
}
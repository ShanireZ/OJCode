#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int p1 = s.find('[') + 1;
    int p2 = s.find("]]", p1) - 1;
    cout << '/';
    for (int i = p1; i <= p2; i++)
    {
        if (isupper(s[i]))
        {
            cout << char(s[i] - 'A' + 'a');
        }
    }
    return 0;
}
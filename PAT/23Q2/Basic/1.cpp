#include <iostream>
#include <string>
using namespace std;
string s;
int main()
{
    int cnt = 0;
    while (getline(cin, s))
    {
        int pos = s.find("fight");
        while (pos != string::npos)
        {
            cnt++;
            pos = s.find("fight", pos + 1);
        }
    }
    cout << cnt << "\n";
    return 0;
}
#include <iostream>
#include <string>
using namespace std;
string s, l = "luogu";
int main()
{
    cin >> s;
    int pos = s.find(l), cnt = 0;
    while (pos != string::npos)
    {
        cnt++;
        pos = s.find(l, pos + 1);
    }
    cout << cnt << endl;
    return 0;
}
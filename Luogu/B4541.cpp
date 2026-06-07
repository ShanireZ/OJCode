#include <algorithm>
#include <iostream>
using namespace std;
string s;
int main()
{
    cin >> s;
    int pos = s.find("AGCT");
    while (pos != string::npos)
    {
        s.replace(pos, 4, "AG/CT");
        pos = s.find("AGCT", pos);
    }
    cout << s << endl;
    return 0;
}
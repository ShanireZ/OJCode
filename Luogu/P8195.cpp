#include <iostream>
#include <string>
using namespace std;
string s;
int main()
{
    cin >> s;
    int pos = s.find("chuanzhi"), cnt = 0;
    while (pos != string::npos)
    {
        cnt++;
        pos = s.find("chuanzhi", pos + 1);
    }
    cout << cnt << endl;
    return 0;
}
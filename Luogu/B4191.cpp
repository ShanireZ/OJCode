#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int a = stoi(s.substr(0, 2));
    int b = stoi(s.substr(3, 2));
    do
    {
        b++;
        if (b == 60)
        {
            b = 0, a++;
        }
        if (a == 24)
        {
            a = 0;
        }
    } while (a / 10 != b % 10 || a % 10 != b / 10);
    if (a < 10)
    {
        cout << 0;
    }
    cout << a << ":";
    if (b < 10)
    {
        cout << 0;
    }
    cout << b << endl;
    return 0;
}
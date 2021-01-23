#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string a, b;
int main()
{
    cin >> a >> b;
    int p = a.find(b, 0);
    int t = 0;

    while (p != string::npos)
    {
        t++;

        if (p == a.size() - 1)
        {
            break;
        }

        p = a.find(b, p + 1);
    }

    cout << t;
    return 0;
}
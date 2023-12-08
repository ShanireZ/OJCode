#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s1;
int main()
{
    cin >> s1;
    s1 += s1[0];
    for (int i = 0; i <= s1.size() - 2; i++)
    {
        char x = s1[i] + s1[i + 1];
        cout << x;
    }
    return 0;
}
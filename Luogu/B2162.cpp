#include <algorithm>
#include <iostream>
using namespace std;
string s;
int main()
{
    int n = 0;
    cin >> s;
    for (char ch : s)
    {
        n = n * 2 + ch - '0';
    }
    cout << n << endl;
    return 0;
}
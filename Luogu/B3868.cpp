#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        int x = 2;
        for (char c : s)
        {
            x = (c >= '0' && c <= '9') ? max(x, c - '0' + 1) : max(x, c - 'A' + 11);
        }
        cout << (x > 2 ? 0 : 1) << " ";
        cout << (x > 8 ? 0 : 1) << " ";
        cout << (x > 10 ? 0 : 1) << " ";
        cout << (x > 16 ? 0 : 1) << endl;
    }
    return 0;
}
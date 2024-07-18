#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    n %= 26;
    char c = 'A' + n;
    for (int i = 1; i <= 26; i++)
    {
        cout << c;
        c = (c + 1 > 'Z' ? 'A' : c + 1);
    }
    return 0;
}
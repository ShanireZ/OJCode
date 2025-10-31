#include <algorithm>
#include <iostream>
using namespace std;
string s;
int main()
{
    int n;
    cin >> n;
    if (n < 2)
    {
        cout << n << endl;
        return 0;
    }
    while (n)
    {
        s += (n % 2 + '0');
        n /= 2;
    }
    reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
}
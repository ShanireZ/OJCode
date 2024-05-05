#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    string h = s.substr(0, 2), m = s.substr(2);
    if (h[0] == '0' && h[1] < '6')
    {
        h[0] = '2', h[1] += 4;
    }
    cout << h << m << endl;
    return 0;
}
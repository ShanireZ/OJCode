#include <algorithm>
#include <iostream>
using namespace std;
string s;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        s += c;
    }
    sort(s.begin(), s.end());
    cout << s << endl;
    return 0;
}
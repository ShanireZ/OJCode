#include <algorithm>
#include <iostream>
using namespace std;
string s;
long long m, ans, ca;
int main()
{
    cin >> s >> m;
    for (char ch : s)
    {
        ch == 'A' ? ca++ : ans += ca;
    }
    cout << max(0ll, ans - m) << endl;
    return 0;
}
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s = to_string(n);
    while(n / 2 != 0)
    {
        n /= 2;
        s += to_string(n);
    }
    cout << s.size() << endl;
    return 0;
}
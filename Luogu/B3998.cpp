#include <algorithm>
#include <iostream>
using namespace std;
string s, t;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        if (t.size() == 1)
        {
            s += t;
        }
        else if(s.size())
        {
            s.erase(s.size() - 1);
        }
    }
    cout << s << endl;
    return 0;
}
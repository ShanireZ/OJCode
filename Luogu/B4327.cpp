#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    string n, res;
    cin >> n;
    if (n.size() % 2)
    {
        n = "0" + n;
    }
    for (int i = 0; i < (int)n.size(); i += 2)
    {
        res = n.substr(i, 2) + res;
    }
    while (res.size() > 1 && res.front() == '0')
    {
        res.erase(0, 1);
    }
    cout << res << endl;
    return 0;
}
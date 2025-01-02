#include <algorithm>
#include <iostream>
using namespace std;
int t[15], c, a;
int main()
{
    for (int i = 1; i <= 4; i++)
    {
        cin >> a;
        if (t[a] == 0)
        {
            c++;
        }
        t[a]++;
    }
    cout << (c == 2 ? "Yes" : "No") << endl;
    return 0;
}
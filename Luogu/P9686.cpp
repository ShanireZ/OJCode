#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        if (s == "AC")
        {
            continue;
        }
        cout << i << " ";
    }
    return 0;
}
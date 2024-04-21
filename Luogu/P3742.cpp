#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n;
    string s1, s2;
    cin >> n >> s1 >> s2;
    for (int i = 0; i < n; i++)
    {
        if(s1[i] < s2[i])
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << s2 << endl;
    return 0;
}
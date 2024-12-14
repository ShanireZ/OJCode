#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        int s1 = 0, s2 = 0;
        for (int j = (int)str.size() - 1; j >= 0; j--)
        {
            j % 2 == 0 ? s1 += str[j] - '0' : s2 += str[j] - '0';
        }
        cout << (s1 % 11 == s2 % 11 ? "Yes" : "No") << endl;
    }
    return 0;
}
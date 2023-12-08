#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s1, s2;
int main()
{
    int cnt = 0;
    double yz;
    cin >> yz;
    cin >> s1 >> s2;
    for (int i = 0; i <= s1.size() - 1; i++)
    {
        if (s1[i] == s2[i])
        {
            cnt++;
        }
    }
    if (1.0 * cnt / s1.size() >= yz)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
    return 0;
}
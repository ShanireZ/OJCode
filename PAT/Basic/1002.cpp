#include <iostream>
#include <sstream>
#include <string>
using namespace std;
string nums[15] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
int main()
{
    string s;
    cin >> s;
    int tot = 0;
    for (char c : s)
    {
        tot += c - '0';
    }
    stringstream ss;
    ss << tot;
    ss >> s;
    for (int i = 0; i < (int)s.size(); i++)
    {
        cout << nums[s[i] - '0'];
        if (i != (int)s.size() - 1)
        {
            cout << " ";
        }
    }
    return 0;
}
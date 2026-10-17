#include <iostream>
#include <sstream>
#include <string>
using namespace std;
string nums[15] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int main() // 統計數字每位和，並轉化為英文
{
    string s;
    cin >> s;
    int tot = 0;
    for (int i = 0; i < int(s.size()); i++)
    {
        tot += s[i] - '0';
    }
    stringstream ss;
    ss << tot;
    ss >> s;
    cout << nums[s[0] - '0'];
    for (int i = 1; i < int(s.size()); i++)
    {
        cout << " " << nums[s[i] - '0'];
    }
    return 0;
}
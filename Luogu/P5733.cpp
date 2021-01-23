#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    string str;
    cin >> str;
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    cout << str;
    return 0;
}
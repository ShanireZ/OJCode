#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    swap(s.front(), s.back());
    cout << stoi(s) << endl;
    return 0;
}
#include <iostream>
#include <string>
using namespace std;
int t[10];
int main()
{
    string s;
    cin >> s;
    for (char c : s)
    {
        t[c - '0']++;
    }
    for (int i = 0; i < 10; i++)
    {
        if (t[i])
        {
            cout << i << ":" << t[i] << "\n";
        }
    }
    return 0;
}
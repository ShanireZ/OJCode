#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
stack<char> s;
int main()
{
    char c;
    while (cin >> c)
    {
        if (c == '(' || c == '[' || c == '<')
        {
            s.emplace(c);
        }
        else if (s.empty() || (s.top() == '(' && c != ')') || (s.top() == '[' && c != ']') || (s.top() == '<' && c != '>'))
        {
            cout << "No" << endl;
            return 0;
        }
        else
        {
            s.pop();
        }
    }
    cout << (s.size() ? "No" : "Yes") << endl;
    return 0;
}
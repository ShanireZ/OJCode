#include <iostream>
#include <stack>
using namespace std;
stack<int> s1, s2;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        if (ch == 'I')
        {
            int x;
            cin >> x;
            s1.push(x);
        }
        else
        {
            int cnt = 0;
            if (s1.empty() && s2.empty())
            {
                cout << "ERROR\n";
            }
            else if (s2.empty())
            {
                while (!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                    cnt += 2;
                }
                cout << s2.top() << " " << cnt + 1 << "\n";
                s2.pop();
            }
            else
            {
                cout << s2.top() << " 1\n";
                s2.pop();
            }
        }
    }
    return 0;
}
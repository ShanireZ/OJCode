#include <iostream>
#include <string>
using namespace std;
unsigned long long s[1000005], x;
int main()
{
    ios::sync_with_stdio(false);
    int n, t;
    cin >> t;
    while (t--)
    {
        int top = 0;
        cin >> n;
        while (n--)
        {
            string cmd;
            cin >> cmd;
            if (cmd == "push")
            {
                cin >> x;
                s[++top] = x;
            }
            else if (cmd == "pop")
            {
                if (top == 0)
                {
                    cout << "Empty\n";
                }
                else
                {
                    top--;
                }
            }
            else if (cmd == "query")
            {
                if (top == 0)
                {
                    cout << "Anguei!\n";
                }
                else
                {
                    cout << s[top] << "\n";
                }
            }
            else
            {
                cout << top << "\n";
            }
        }
    }
    return 0;
}
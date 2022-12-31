#include <iostream>
#include <list>
using namespace std;
list<int> p[1000005];
int main()
{
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int a, x;
        string cmd;
        cin >> cmd >> a;
        if (cmd == "size")
        {
            cout << p[a].size() << "\n";
        }
        else if (cmd == "front" && p[a].size())
        {
            cout << p[a].front() << "\n";
        }
        else if (cmd == "back" && p[a].size())
        {
            cout << p[a].back() << "\n";
        }
        else if (cmd == "push_back")
        {
            cin >> x;
            p[a].push_back(x);
        }
        else if (cmd == "push_front")
        {
            cin >> x;
            p[a].push_front(x);
        }
        else if (cmd == "pop_back" && p[a].size())
        {
            p[a].pop_back();
        }
        else if (cmd == "pop_front" && p[a].size())
        {
            p[a].pop_front();
        }
    }
    return 0;
}
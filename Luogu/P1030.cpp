#include <iostream>
#include <string>
using namespace std;
void traversal(string mid, string tail)
{
    if (mid.size() == 0)
    {
        return;
    }
    char root = tail[tail.size() - 1];
    cout << root;
    int pos = mid.find(root);
    traversal(mid.substr(0, pos), tail.substr(0, pos));
    traversal(mid.substr(pos + 1), tail.substr(pos, tail.size() - pos - 1));
}
int main()
{
    string mid, tail;
    cin >> mid >> tail;
    traversal(mid, tail);
    return 0;
}
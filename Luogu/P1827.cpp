#include <iostream>
#include <string>
using namespace std;
void dfs(string mid, string pre)
{
    if (mid.size() == 0)
    {
        return;
    }
    char root = pre[0];
    int pos = mid.find(root);
    dfs(mid.substr(0, pos), pre.substr(1, pos));
    dfs(mid.substr(pos + 1), pre.substr(pos + 1));
	cout << root;
}
int main()
{
    string mid, pre;
    cin >> mid >> pre;
    dfs(mid, pre);
    return 0;
}
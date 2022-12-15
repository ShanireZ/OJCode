#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
struct Node
{
    string start, over;
    int data;
};
vector<vector<Node>> blks;
string s;
int n, k;
map<string, Node> m;
int main()
{
    cin >> s >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        Node v;
        cin >> v.start >> v.data >> v.over;
        m[v.start] = v;
    }
    while (s != "-1")
    {
        vector<Node> nodes;
        while (nodes.size() < k && s != "-1")
        {
            nodes.push_back(m[s]);
            s = m[s].over;
        }
        blks.push_back(nodes);
    }
    reverse(blks.begin(), blks.end());
    for (int i = 0; i < blks.size(); i++)
    {
        for (int j = 0; j < blks[i].size(); j++)
        {
            if (i != 0 || j != 0)
            {
                cout << blks[i][j].start << endl;
            }
            cout << blks[i][j].start << " " << blks[i][j].data << " ";
        }
    }
    cout << -1;
    return 0;
}
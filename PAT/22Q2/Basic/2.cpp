#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Node
{
    string id;
    int v, sx;
    bool operator<(const Node oth) const
    {
        if (v == oth.v)
        {
            return sx < oth.sx;
        }
        return v > oth.v;
    }
};
vector<Node> ns[10];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string id;
        cin >> id;
        int v, tot = 0, cnt = 0;
        for (int j = 1; j <= 7; j++)
        {
            cin >> v;
            if (v)
            {
                ns[j].push_back(Node{id, v, i});
                tot += v, cnt++;
            }
        }
        if (tot && cnt >= 3)
        {
            ns[8].push_back(Node{id, tot, i});
        }
    }
    for (int i = 1; i <= 8; i++)
    {
        cout << "Star ";
        if (i <= 7)
        {
            cout << i << "\n";
        }
        else
        {
            cout << "of the week\n";
        }
        sort(ns[i].begin(), ns[i].end());
        if ((int)ns[i].size() == 0)
        {
            cout << "NONE\n";
        }
        else
        {
            cout << ns[i][0].id << "\n";
            for (int j = 1; j < (int)ns[i].size() && ns[i][j].v == ns[i][0].v; j++)
            {
                cout << ns[i][j].id << "\n";
            }
        }
    }
    return 0;
}
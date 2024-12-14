#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int st, ed;
    bool operator<(const Node &oth) const
    {
        return (ed == oth.ed ? st < oth.st : ed < oth.ed);
    }
};
vector<Node> ns;
int main()
{
    int T, n, ok;
    cin >> T;
    while (T--)
    {
        ns.clear(), ok = 1;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            string s;
            cin >> s;
            for (int j = 1; j < (int)s.size() && ok; j++)
            {
                ok = (s[j - 1] <= s[j]);
            }
            ns.push_back(Node{s.front() - 'a', s.back() - 'a'});
        }
        sort(ns.begin(), ns.end());
        for (int i = 1; i < n && ok; i++)
        {
            ok = (ns[i].st >= ns[i - 1].ed);
        }
        cout << ok << endl;
    }
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> a, b;
void dfs(vector<string> st, vector<string> ed, int step, int maxstep)
{
    ed.clear();
    if (step > maxstep)
    {
        for (int i = 0; i < st.size(); i++)
        {
            cout << st[i] << endl;
        }
        return;
    }
    int mid = st.size();
    ed.resize(mid * 2);
    for (int i = 0; i < mid; i++)
    {
        ed[i].append(mid, ' ');
        ed[i].append(st[i]);
        ed[i].append(mid, ' ');
    }
    for (int i = mid; i < mid * 2; i++)
    {
        ed[i].append(st[i - mid]).append(st[i - mid]);
    }
    dfs(ed, st, step + 1, maxstep);
}
int main()
{
    int n;
    cin >> n;
    a.push_back(" /\\ ");
    a.push_back("/__\\");
    dfs(a, b, 2, n);
    return 0;
}